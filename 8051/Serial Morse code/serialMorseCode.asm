ORG 0000H

LED	EQU P0.1


JMP MAIN1


MAIN1:
	SETB EA
	MOV TMOD, #21H
	MOV TCON, #00h
	MOV TH1, #0FDH
	MOV SCON, #50H
	SETB TR1
	
LOOP:
	JNB RI, LOOP
	CLR RI
	MOV A, SBUF
	
LETRA_U:
	CJNE A, #'U', LETRA_E
	CLR LED
	LCALL DELAY_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_1_MEIO
	SETB LED
	LCALL DELAY_1_MEIO
	JMP LOOP
LETRA_E:
	CJNE A, #'E', LETRA_P
	CLR LED
	LCALL DELAY_MEIO
	SETB LED
	LCALL DELAY_1_MEIO
	JMP LOOP
LETRA_P:
	CJNE A, #'P', LETRA_G
	CLR LED
	LCALL DELAY_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_1_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_1_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_MEIO
	SETB LED
	LCALL DELAY_1_MEIO
	JMP LOOP
LETRA_G:
	CJNE A, #'G', LOOP
	CLR LED
	LCALL DELAY_1_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_1_MEIO
	SETB LED
	LCALL DELAY_MEIO
	CLR LED
	LCALL DELAY_MEIO
	SETB LED
	LCALL DELAY_1_MEIO
	JMP LOOP


;Subrotinas de atraso
DELAY_MEIO:			 ;Meio segundo de atraso
	MOV R0, #8		 ;Atribui 8 para R0
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
DELAY_1_MEIO:		 	 ;10 segundos de atraso
	MOV R1, #3	 	 ;Atribui 3 para R1
DELT2:
	LCALL DELAY_MEIO	 ;Pula para a label Delay_Meio
	DJNZ R1, DELT2           ;Decremento e retorno se for zero para Delt2
	RET			 ;Retorno para o LCALL que o chamou
DELAY_3_MEIO:			 ;30 segundos de atraso
	MOV R2, #7  	 	 ;Atribui 7 para R2
DELT3:
	LCALL DELAY_MEIO	 ;Pula para a label Delay_Meio
	DJNZ R2, DELT3           ;Decremento e retorno se for zero para Delt3
	RET			 ;Retorno para o LCALL que o chamou
