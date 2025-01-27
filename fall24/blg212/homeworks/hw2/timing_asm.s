; This part belong to me
		AREA	SysTick_Definitions, DATA, READONLY
SysTick_CTRL	EQU 0xE000E010		; SysTick Control and STATES Register.
SysTick_LOAD	EQU 0xE000E014		; SysTick Reload Value Register
SysTick_VAL		EQU 0xE000E018		; SysTick Current Value Register


		AREA    Timing_Code, CODE, READONLY
        ALIGN
        THUMB
        EXPORT  Systick_Start_asm
        EXPORT  Systick_Stop_asm
		EXPORT	SysTick_Handler 	; When the correct time comes,
									; remove this from the comments.
		EXTERN	ticks
		EXTERN	SystemCoreClock

SysTick_Handler FUNCTION
		PUSH	{LR}
		; You should only increment ticks here.
		PUSH	{R0, R1}			; Save the registers that will be used
		
		LDR		R0, =ticks			; Load the address of ticks
		LDR		R1, [R0]			; Load the value of ticks
		ADDS	R1, R1, #1			; Incremnet the value
		STR		R1, [R0]			; Store the incremented value
		
		POP		{R0, R1}
		POP		{PC}
		ENDFUNC

Systick_Start_asm FUNCTION
		PUSH	{LR}
		; You should initialize SysTick here.		
		; Pushing registers can cause problems
		PUSH	{R0-R3}				; Save the registers that will be modified
		
		; Reset ticks
		LDR		R0, =ticks			; Load the address of ticks to R0
		MOVS	R1, #0				; R1 = 0x0
		STR		R1, [R0]			; [R0] = 0x0
		
		; Calculate reload value
		LDR		R0, =SysTick_LOAD	; Load the address of SysTick LOAD register
		LDR		R1, =SystemCoreClock	; Load scc address
		LDR		R2, [R1]			; R2 = value of scc
		LDR		R1, =100000			; Divisor (for 1us interval)
		; R0 = SysTick_LOAD
		; R1 = 100000
		; R2 = SystemCoreClock value
		
		BL		Division			; Call division function
		
		; Reload value
		LDR		R0, =SysTick_LOAD	; Load the address of SysTick LOAD
		SUBS	R3, R3, #1			; Subtract extra 1 from the result
		STR		R3, [R0]			; Quotient stored in SysTick_LOAD
		
		; Reset current val
		LDR		R0, =SysTick_VAL	; Load the address of SysTick_VAL
		MOVS	R1, #0				; Reset r1
		STR		R1, [R0]			; Resets the current value
		
		; Configure and ENABLE timer
		LDR 	R0, =SysTick_CTRL	; Load the address of SysTick_CTRL
		LDR		R1, =0x00000007		; Load the control word (ENABLE | TICKINT | CLKSOURCE)
		STR		R1, [R0]			; Store the control word
		
		POP		{R0-R3}				; Restore the saved registers
        POP		{PC}
		ENDFUNC

Division FUNCTION
	; Input: R2 = dividend, R1 = divisor
	; Output: R3 = quotient
		MOVS	R3, #0				; Initialize quotient to 0
		MOVS	R0, R2				; R0 = dividend
Loop
		CMP		R0, R1				; Compare dividend and divisor
		BLT		end_divide			; End when r2 < r1
		SUBS	R0, R0, R1			; R2 = R2 - R1
		ADDS	R3, R3, #1			; Increment quotient
		B 		Loop				; Repeat the loop
end_divide
		BX		LR					; Return
		ENDFUNC



Systick_Stop_asm FUNCTION
		PUSH	{LR}
		; You should stop SysTick, zero the ticks,
			; and return "non-zero value of ticks".
		PUSH	{R1-R2}				; Save the registers that will be modified
		; r0 is return so i do not want restore it
		
		; Stop SysTick by clearing the enable flag
		LDR		R0, =SysTick_CTRL	; Load SysTick control register address
		LDR		R1, [R0]			; Load the current value of the SysTick control register
		; ENABLE_Mask
		LDR		R2, =0xFFFFFFFE		; Create a mask to clear the ENABLE flag (1..10)
		ANDS	R1, R1, R2			; Clears the 0th bit (ENABLE) of R1
		STR		R1, [R0]			; Write the updated value back to SysTick_CTRL
		
		; Read ticks
		LDR		R0, =ticks			; Load the address of ticks
		LDR		R1, [R0]			; Save the ticks to R1
		
		; Reset ticks
		MOVS	R2, #0				; R2 = 0x0
		STR		R2, [R0]			; Reset the ticks
		
		; Return must be in R0
		MOV		R0, R1				; R0 = #ticks
		
		POP		{R1-R2}				; Restore the saved registers			
		POP		{PC}
		ENDFUNC
		END
