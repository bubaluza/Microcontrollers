// --- Variveis Globais ---
unsigned int valADC;             // variavel de recebimento
unsigned char unidade,dec1;      // variaveis dos digitos de unidade e decimal

// --- Macros ---
#define disp_lcd    Lcd_Chr(2,2,unidade+48);    Lcd_Chr_Cp('.'); Lcd_Chr_Cp(dec1+48); Lcd_chr_cp(86);     //macro para concatenar os digitos de unidade e decimal em junção de um ponto

// --- Inicialização LCD ---

    // Lcd pinout settings
    sbit LCD_RS at RD7_bit;
    sbit LCD_EN at RD6_bit;
    sbit LCD_D7 at RD5_bit;
    sbit LCD_D6 at RD4_bit;
    sbit LCD_D5 at RC7_bit;
    sbit LCD_D4 at RC6_bit;

    // Pin direction
    sbit LCD_RS_Direction at TRISD7_bit;
    sbit LCD_EN_Direction at TRISD6_bit;
    sbit LCD_D7_Direction at TRISD5_bit;
    sbit LCD_D6_Direction at TRISD4_bit;
    sbit LCD_D5_Direction at TRISC7_bit;
    sbit LCD_D4_Direction at TRISC6_bit;

// --- Programa principal ---
void main() {
    ADC_Init();                                 // inicializa ADC
    Lcd_Init();                                 // inicializa LCD
    Lcd_Cmd(_LCD_TURN_ON);                      // habilita o visor LCD
    Lcd_Cmd(_LCD_CLEAR);                        // limpa a tela do lcd
    Lcd_Cmd(_LCD_CURSOR_OFF);                   // Desgalia o cursor
    Lcd_Out(1,1, "Iniciando...");               // escreve "Iniciando..." no visor LCD
    Delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);                        // limpa a tela do lcd
    Lcd_Out(1,1, "TENSAO:");                    // escreve "TENSAO:" no visor LCD
    
      while(1)
      {
        valADC= ADC_Read(0);                    // leitura de valor analogico na porta An0
        unidade = ((valADC*5)/1024)%10;         // conversão para retirar somente o digito referente a unidade
        dec1 = ((((valADC*5)%1024)*10)/1024);   // conversão para retirar somente o digito referente ao primeiro decimal
        disp_lcd;                               // chama macro
        Delay_ms(300);
      }                                         // laço infinito
}
