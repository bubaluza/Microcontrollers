ORG 0000h                        ;Começo do programa e retorno do RESET
LED		EQU P0		 ;Declaração das portas
VERMELHO	EQU P0.0
AMARELO   	EQU P0.1
VERDE		EQU P0.2
INTERRUPCAO 	EQU P0.3
MOV IE, #10000100b		 ;Ativa as interrupções e a interrupção INT1
MOV TMOD, #00000001b		 ;Seta o timer de 16bits
LJMP MAIN			 ;Jump para a função principal
;Início da interrupção
ORG  0013h
		MOV R5, P0	 ;MOVs: salvam os estados antes das interrupções
		MOV R3, TH0
		MOV R4, TL0
		MOV A, R0
		MOV B, R1
		MOV R6, B
		MOV B, R2
		CLR INTERRUPCAO	 ;Acente o LED da interrupção
		LCALL DELAY_10	 ;Pula para a label Delay_10
		SETB VERDE	 ;Apaga o LED VERDE
		SETB AMARELO	 ;Apaga O LED AMARELO
		CLR VERMELHO	 ;Acende o LED VERMELHO
		LCALL DELAY_10   ;Pula para a label Delay_10
		SETB VERMELHO	 ;Apaga o LED VERMELHO
		MOV R0, A 	 ;MOVs: Retornam aos estados antes da interrupção
		MOV R2, B
		MOV B, R6
		MOV R1, B
		MOV P0, R5
		MOV TH0, R3
		MOV TL0, R4
		SETB TR0
		SETB INTERRUPCAO
RETI				 ;Retorno ao estado antes da interrupção
;Rotina principal do programa
MAIN:
		CLR VERMELHO     ;Acende o LED VERMELHO
		LCALL DELAY_30   ;Pula para a subrotina de Delay_30
		SETB VERMELHO	 ;Apaga o LED VERMELHO
		CLR VERDE	 ;Acende o LED VERDE
		LCALL DELAY_30   ;Pula para a subrotina de Delay_30
		SETB VERDE	 ;Apaga o LED VERDE
		CLR AMARELO	 ;Acende o LED AMARELO
		LCALL DELAY_2    ;Pula para a subrotina de Delay_2
		SETB AMARELO	 ;Apaga o LED AMARELO
		LCALL MAIN	 ;Retorna para o início do main
;Subrotinas de atraso
DELAY_2:			 ;2 segundos de atraso
	MOV R0, #32		 ;Atribui 32 para R0
DELT:
	MOV TH0, #0DH		 ;THigh(TH0) e TLow(TL0) equivalem a 3333
	MOV TL0, #05H
	SETB TR0		 ;Inicia o contador, TR0 = 1
TIME:				 ;Tempo para 62203 pulsos, aproximandamente 62ms
	JNB TF0, TIME		 ;Pula para TIME se a flag for igual a 1
	CLR TR0			 ;Para o contador, TR0 = 0
	CLR TF0			 ;Limpa a flag do timer, TF0 = 0
	DJNZ R0, DELT            ;Decremento e retorno se for zero para Delt
	RET			 ;Retorno para o LCALL que o chamou
DELAY_10:		 	 ;10 segundos de atraso
	MOV R1, #5	 	 ;Atribui 5 para R1
DELT2:
	LCALL DELAY_2		 ;Pula para a label Delay_2
	DJNZ R1, DELT2           ;Decremento e retorno se for zero para Delt2
	RET			 ;Retorno para o LCALL que o chamou
DELAY_30:			 ;30 segundos de atraso
	MOV R2, #3  	 	 ;Atribui 3 para R2
DELT3:
	LCALL DELAY_10		 ;Pula para a label Delay_10
	DJNZ R2, DELT3           ;Decremento e retorno se for zero para Delt3
	RET			 ;Retorno para o LCALL que o chamou
