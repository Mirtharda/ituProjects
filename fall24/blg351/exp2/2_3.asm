;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
			.data                   ; Data section
counter     .byte 0x00             ; 4-bit variable to store the count

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------

                                            
; Initialization

SetupP2  	mov.b	#00000000b, &P2SEL
			mov.b   #11111101b, &P2DIR
            mov.b   #00000010b, &P2OUT
            mov.b   #11111111b, &P1DIR
            mov.b   #00000000b, &P1OUT

MainLoop    bit.b   #00000010b, &P2IN   	; Check if P2.1 is pressed
         	jnz     MainLoop       		; If not pressed, stay in loop

; Increment Counter
	      	mov.b   counter, R5    		; Ccounter value into R5
	        inc.b   R5             		; Increment R5
	        cmp.b   #16, R5        		; Check if R5 equals 16
	        jne     UpdateCounter
	        mov.b   #0, R5         		; If 16, reset R5 to 0

UpdateCounter
            mov.b   R5, counter
            mov.b   counter, &P1OUT

Wait  		bit.b   #00000010b, &P2IN
            jz      Wait

            jmp     MainLoop       		; Go back to main loop

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
