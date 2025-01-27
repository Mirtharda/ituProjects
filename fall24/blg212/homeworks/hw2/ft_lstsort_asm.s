; Function: ft_lstsort_asm
; Parameters:
;   R0 - Pointer to the list (address of t_list *)
;   R1 - Pointer to comparison function (address of int (*f_comp)(int, int))
        AREA    Sorting_Code, CODE, READONLY
        ALIGN
        THUMB
        EXPORT  ft_lstsort_asm

ft_lstsort_asm FUNCTION
		PUSH	{R0-R1, LR}
		;LDR	R3, [SP]	 ; you will see the first argument
								; of the function in R3
		;LDR	R3, [SP, #4] ; you will see the second argument
								; of the function in R3
		; Given a singly linked list,
			; sort it using bubble sort by swapping nodes
			
 		MOVS	R2, #1			; Swap flag
		
outer	
		CMP		R2, #0			; Check if swap occured
		BEQ		_end			; No swap, then the list is sorted

		LDR		R4, [R0]		; current = head
		MOVS	R3, #0			; R3 = prev = null
		MOVS	R2, #0			; swap flag = 0
		
inner
		; R3 : prev
		; R4 : current
		; R6 : current->next
		CMP		R4, #0			; Check if current = NULL
		BEQ		outer			; No current, then brancj to outer
		
		ADDS	R6, R4, #4		; [R6] = current->next
		LDR		R7, [R6]		; R7 = current->next
		MOV		R6, R7			; R6 = current->next
		
		CMP		R6, #0			; Check if current->next = NULL
		BEQ		outer			; No next, then branch to outer
		
		; Call ft_cmp(a, b) (in R1)
		PUSH	{R0}			; R0 will be changed so save it
		PUSH	{R1-R4} 		; Save the registers that will be changed by function to stack		
		LDR		R0, [R4]		; R0 = a = current->value		
		MOV		R4, R1			; R3 = ft_cmp		
		LDR		R1, [R6]		; R1 = b = next->value
		BLX		R4				; Call ft_cmp	
		; Return is in R0		
		POP		{R1-R4} 		; Restore the registers
		
		; If R0 = 1 no_swap
		; R0 = 0 swap
		CMP		R0, #1			; a < b
		BEQ		no_swap			; then branch to no_swap
		
		; SWAP
		; nextler swaplenmeli
		CMP		R3, #0			; check if current is head
		BEQ		change_head		; current is head so change head
		
		STR		R6, [R3, #4]	; prev->next = current->next
		LDR		R7, [R6, #4]	; R7 : r6->next
		STR		R7, [R4, #4]	; current->next = R6->next
		STR		R4, [R6, #4]	; R6->next = current
		
		MOVS	R2, #1			; swap flag = 1
		B		no_swap			; go to no_swap
		
change_head
		POP		{R0}			; restore R0 because the memory location it points will be changed
		STR		R6, [R0]		; head = current->next
		LDR		R7, [R6, #4]	; R7 : R6->next
		STR		R7, [R4, #4]	; current->next = r6->next
		STR		R4, [R6, #4]	; r6->next = current
		
		MOVS	R2, #1			; swap flag = 1
		B 		head_changed	; passes the popping part
		
no_swap
		POP		{R0}			; restore r0
head_changed		
		MOV		R3, R4			; prev = current
		MOV		R4, R6			; current = current->next
		B		inner			; repeat the inner loop
			
_end		
		POP		{R0-R1, PC}
		ENDFUNC
		END