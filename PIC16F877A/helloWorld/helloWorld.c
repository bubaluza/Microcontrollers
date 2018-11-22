void main() {
  TRISD = 0x00;          // seta as portas d como saidas

  do {
    PORTD = 0x00;        // desliga as saidas D
    delay_ms(1000);      // delay de 1000ms/1s
    PORTD = 0xFF;        // liga as saidas D
    delay_ms(1000);      // delay de 1000ms/1s
  } while(1);            // loop
}
