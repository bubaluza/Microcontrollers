LED  	EQU P0				;define LED P0

;INICIATION
          MOV SP,#3FH			;stack
          MOV LED,#00h			;led=0
;MAIN
LOOP:     MOV LED,#0FFh			;all P0 pins HIGH
          LCALL DELAY1S			;call  DELAY1S
          MOV LED,#00h			;all P0 pins LOW
          LCALL DELAY1S			;call  DELAY1S
          LJMP LOOP			;loop call

;DELAY FUNCTIONS
					;1 second delay
DELAY1S:  MOV A,#10   			;move 10 to accumulator A
AUX:      LCALL DELAY100		;call DELAY100
          DJNZ A, AUX			;if A!=0 decrement A and call AUX 
          RET				;return
	  
					;100ms delay
DELAY100: MOV B,#100    		;move 100 to accumulator B
AUX2:     LCALL DELAY1MS		;call DELAY1MS
          DJNZ B, AUX2			;if B!=0 decrement B and call AUX2 
          RET
    
    					;1ms delay
DELAY1MS: MOV R0,#150   		;move 150 to R0
          NOP				;NOP to spend machine cycle
          NOP
          NOP
          NOP
          NOP
          DJNZ R0, $-5			;if R0!=0 decrement R0 and back 5 lines
          RET				;return
