;	Programa destinado a disciplina de microControladores da Universidade Estadual de Ponta Grossa
;	Curso de Engenharia de computação, Quarto Ano, 2018
;	Esse programa destina-se a implementação de um 'hello world' na linguagem assembly em PIC
;	PIC16F877A
;	Autor: Gabriel João Schiller, Gabriel Oliveira, Luiz Otávio



	list p=16f877a				;MicroControlador utilizado PIC16F877A
	
; --- Arquivos incluídos no projeto ---
	#include <pic16f877a.inc>		;Biblioteca do pic16f877a
	
; --- Fuse Bit ---
;cristal oscilador externo 12 mhz, sem watchdog, com power up timer, sem proteção de código
	__config _HS_OSC & _WDT_OFF & _PWRTE_ON & _CP_OFF 
	
; --- Paginação de memória ---
; bank3
; bsf	STATUS, RP1
; bsf	STATUS, RP0
;
; bank2
; bsf	STATUS, RP1
; bcf	STATUS, RP0
;
; bank1
; bcf	STATUS, RP1
; bsf	STATUS, RP0
;
;bank0
; bcf	STATUS, RP1
; bcf	STATUS, RP0

; --- Saídas ---
#define led		PORTD,3
	
; --- Vetor de RESET ---
			org		H'0000'				;Origem no endereço 0000h de memória
			goto	inicio				;desvia para inicio

; --- Vetor de interrupção ---
			org		H'0004'				;endereço de interrupção
			retfie						;retorna interrupção
	
; --- Programa de interrupção ---
			
inicio:
			bcf	STATUS, RP1
			bsf	STATUS, RP0				;mudamos para o bank1
			
			movlw	H'00'				;w= b'0000 0000'
			movwf	TRISD				;todas os pinos D são configuradas para saida
			bcf	STATUS, RP1
			bcf	STATUS, RP0				;mudamos para o bank0
			movlw	H'00'
			movwf	PORTD
			call delay
			movlw	H'FF'
			movwf	PORTD
			call delay
			goto	inicio
			
			
; --- Subrotinas ---
delay:
			movlw 	d'250'
			movwf	H'20'
					;2 ciclos
aux1:
			movlw	d'250'
			movwf	H'21'
					;2 ciclos

aux2:		
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			decfsz	H'21'
			goto	aux2	;50*250 ciclos =12500 ciclos
			
			decfsz 	H'20'
			goto	aux1	;250*12500=250000
					;com um cristal de 12mhz aproximadamente 1s de delay
			return

			end
			
