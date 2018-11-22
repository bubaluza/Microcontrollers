LED	EQU P0
LED1	EQU P0.0

;INICIAÇÃO
		MOV SP,#3FH
		MOV LED,#00h

;PROCESSO
CICLO:		MOV LED,#0FFh
		LCALL ATRASO
		MOV LED,#00h
		LCALL ATRASO
		LJMP CICLO

;SUBROTINA DE ATRASO

ATRASO: 	MOV A,#10		;atraso de 1s
AQUI:		LCALL ATRASO2
		DJNZ A, AQUI
		RET

ATRASO2: 	MOV B,#100		;atraso de 100ms
AQUI2:		LCALL ATRASO3
		DJNZ B, AQUI2
		RET
		
ATRASO3: 	MOV R0,#150		;atraso de 1ms
		NOP
		NOP
		NOP
		NOP
		NOP
		DJNZ R0, $-5
		RET
