EZONA	EQU P3
EZONA1	EQU P3.1
EZONA2	EQU P3.2
EZONA3	EQU P3.3
EZONA4	EQU P3.4

;INICIAÇÃO
		MOV SP,#3FH
		MOV P2,#0FFh		;apaga o 7 segmentos
		MOV P3,#00H		;seta como 0 as portas P3
LOOP:					;começo do loop
		MOV A, #00H

ZONA1:		JNB EZONA1, ZONA2	;verifica se zona 1 é ativada
		INC A			;se ativada, incrementa acumulador

ZONA2:		JNB EZONA2, ZONA3	;verifica se zona 2 é ativada
		INC A			;se ativada, incrementa acumulador

ZONA3:		JNB EZONA3, ZONA4	;verifica se zona 3 é ativada
		INC A			;se ativada, incrementa acumulador
		
ZONA4:		JNB EZONA4, CHECK	;verifica se zona 2 é ativada
		INC A			;se ativada, incrementa acumulador

CHECK:		JNZ LIGHT1		;checa acumulador, e pula para Light1 se ele não for 0
		JMP NOTHING		;pula para nothing
		
LIGHT1:		CJNE A, #04h, LIGHT2	;checa se o acumulador e 4
		jmp LIGHTA		;pula para lightA
LIGHT2:		CJNE A, #03h, LIGHT3	;checa se o acumulador e 3
		jmp LIGHTA
LIGHT3:		CJNE A, #02h, SINGLE	;checa se o acumulador e 2
		jmp LIGHTA
		
SINGLE:		JB EZONA1, LLIGHT1	;checa se zona 1 está ativada
		JB EZONA2, LLIGHT2	;checa se zona 2 está ativada
		JB EZONA3, LLIGHT3	;checa se zona 3 está ativada
		JB EZONA4, LLIGHT4	;checa se zona 4 está ativada
NOTHING:
		MOV P2, #92h		;acende S em 7 segmentos
		JMP LOOP

lIGHTA: 	MOV P2, #88H		;acende A em 7 segmentos
		JMP LOOP
		
LLIGHT1:
		MOV P2, #0F9H		;acende 1 em 7 segmentos
		JMP LOOP
LLIGHT2:
		MOV P2, #0A4h		;acende 2 em 7 segmentos
		JMP LOOP
LLIGHT3:
		MOV P2, #0B0h		;acende 3 em 7 segmentos
		JMP LOOP
LLIGHT4:
		MOV P2, #99h		;acende 4 em 7 segmentos
		JMP LOOP	
