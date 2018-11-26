;	Program destined to microprocessor disciplines From Universidade Estadual de Ponta Grossa(UEPG)
;	Computer Engineering, fourth year, 2018
;	this program implements a 'hello world' in assembly to PIC
;	PIC16F877A
;	Author: Gabriel João Schiller



	list p=16f877a				;used microcontroller PIC16F877A
	
; --- FILE INCLUDE ---
	#include <pic16f877a.inc>		;library to pic16f877a
	
; --- Fuse Bit ---
;extern crystal oscillator, watchdog OFF, powerup time, code proctection OFF
	__config _HS_OSC & _WDT_OFF & _PWRTE_ON & _CP_OFF 
	
; --- memory pagination ---
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

; --- OUTPUTS ---
#define led		PORTD,3
	
; --- org reset ---
			org		H'0000'				;Origin memory address 0000h
			goto	inicio					;go to inicio

; --- org interruption ---
			org		H'0004'				;interruption memory address
			retfie						;return interruption
	
; --- main program ---
			bcf	STATUS, RP1
			bsf	STATUS, RP0				;select bank1
			
			movlw	H'00'					;work= b'0000 0000'
			movwf	TRISD					;set PinD OUTPUT
			bcf	STATUS, RP1
			bcf	STATUS, RP0				;select bank0
			
loop:
			movlw	H'00'
			movwf	PORTD					;pinD LOW
			call delay			
			movlw	H'FF'			
			movwf	PORTD					pinD HIGH
			call delay
			goto	loop					
			
			
; --- Functions ---
delay:
			movlw 	d'250'
			movwf	H'20'
aux1:
			movlw	d'250'
			movwf	H'21'
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
			goto	aux2	;50*250 = 12500 cycles
			
			decfsz 	H'20'
			goto	aux1	;250*12500=3125000 cycles
					;with 12Mhz crystal oscillator = 1s delay
			return
			end
