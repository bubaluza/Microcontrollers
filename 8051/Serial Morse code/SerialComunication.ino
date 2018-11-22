void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
}

char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    
    rx_byte = Serial.read();       // get the character
  
    // check if a number was received
    if (rx_byte == 'u' || rx_byte == 'U') {
      Serial1.write('U');
    }
    if (rx_byte == 'e' || rx_byte == 'E') {
      Serial1.write('E');
    }
    if (rx_byte == 'p' || rx_byte == 'P') {
      Serial1.write('P');
    }
    if (rx_byte == 'g' || rx_byte == 'G') {
      Serial1.write('G');
    } 
    delay(5000); 
  } // end: if (Serial.available() > 0)  
  
}


