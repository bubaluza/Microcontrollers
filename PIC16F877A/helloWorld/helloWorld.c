void main() {
  TRISD = 0x00;          // set pinD as OUTPUT

  do {
    PORTD = 0x00;        // pinD LOW
    delay_ms(1000);      // delay 1000ms/1s
    PORTD = 0xFF;        // pinD HIGH
    delay_ms(1000);      // delay 1000ms/1s
  } while(1);            // loop
}
