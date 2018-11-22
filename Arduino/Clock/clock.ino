#include <LiquidCrystal.h>
#include "TimerOne.h"
char horario[9] = "";
char data[10] = "";
int dia = 8;
int mes = 10;
int ano = 2018;
int segundo = 23;
int minuto = 27;
int hora = 18;

int diaConf = 1;
int mesConf = 1;
int anoConf = 2018;
int segundoConf = 0;
int minutoConf = 0;
int horaConf = 0;

int segundoAlarm = 0;
int minutoAlarm = 0;
int horaAlarm = 0;
bool alarm = 0;

int opcao = 1;


bool configuracao = 0;
bool alarmActivate = 0;
bool primeiraleitura = 1;
long tempo;
bool lastRead = LOW;
bool segurou = 0;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define clockUpdate sprintf(horario, "%02d:%02d:%02d", hora, minuto, segundo);  lcd.setCursor(0,0); lcd.print(horario); if(alarm){ lcd.setCursor(13,0); lcd.write(2);} else {lcd.setCursor(13,0); lcd.print(" ");}
#define clockUpdateConf sprintf(horario, "%02d:%02d:%02d", horaConf, minutoConf, segundoConf);  lcd.setCursor(0,0); lcd.print(horario);

#define clockAlarm sprintf(horario, "%02d:%02d:%02d", horaAlarm, minutoAlarm, segundoAlarm);  lcd.setCursor(0,0); lcd.print("Alarm:      "); lcd.setCursor(0,1); lcd.print(horario); lcd.print("  "); if(alarm){ lcd.setCursor(13,0); lcd.write(2);} else {lcd.setCursor(13,0); lcd.print(" ");}

#define dataUpdate sprintf(data, "%02d/%02d/%4d", dia, mes, ano); lcd.setCursor(0, 1); lcd.print(data);
#define dataUpdateConf sprintf(data, "%02d/%02d/%4d", diaConf, mesConf, anoConf); lcd.setCursor(0, 1); lcd.print(data);


byte alarmIcon[] = {
  B00100,
  B01110,
  B10101,
  B10101,
  B10111,
  B10001,
  B01010,
  B00100
};

void nextTime() {
  segundo++;
  if (segundo >= 60) {
    segundo = 0;
    minuto++;
  }
  if (minuto >= 60) {
    minuto = 0;
    hora++;
  }
  if (hora >= 24) {
    hora = 0;
    dia++;
  }

  if ( ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) || ( (mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && dia > 30) || ( (mes == 2) && dia > 28) ) {
    dia = 1;
    mes++;
  }
  if (mes > 12) {
    mes = 1;
    ano++;
  }
}
int interru = 0;
void configMode1() {
  interru++;
  Serial.println(interru);
  if (interru > 2) {
    configuracao = 1;
    detachInterrupt(digitalPinToInterrupt(2));
    diaConf = dia;
    mesConf = mes;
    anoConf = ano;
    segundoConf = segundo;
    minutoConf = minuto;
    horaConf = hora;
    primeiraleitura = 1;
    interru = 0;
  }
}

void setup() {
  Timer1.initialize(1000000);    //1030000
  Timer1.attachInterrupt(nextTime);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  lcd.begin(16, 2);
  lcd.createChar(2, alarmIcon);
  lcd.clear();
  attachInterrupt(digitalPinToInterrupt(2), configMode1, FALLING );
  Serial.begin(9600);
}





void loop() {
  if ( configuracao) {
    if (primeiraleitura) {
      lcd.setCursor(15, 0);
      lcd.print("S");
      lcd.setCursor(11, 1);
      lcd.print("Alarm");
      lcd.cursor();
      primeiraleitura = 0;
    }


    bool leitura2 = digitalRead(2);

    if (digitalRead(3) == HIGH) {
      while (digitalRead(3)) {
      }
      opcao++;
      if (opcao > 8) {
        opcao = 1;
      }
    }

    switch (opcao) {
      case 1:                //hora
        lcd.setCursor(1, 0);
        break;
      case 2:                //minuto
        lcd.setCursor(4, 0);
        break;
      case 3:                //segundo
        lcd.setCursor(7, 0);
        break;
      case 4:
        lcd.setCursor(15, 0); //sair
        break;
      case 5:               //dia
        lcd.setCursor(1, 1);
        break;
      case 6:               //mes
        lcd.setCursor(4, 1);
        break;
      case 7:               //ano
        lcd.setCursor(9, 1);
        break;
      case 8:               // alarme
        lcd.setCursor(13, 1);
        break;
    }


    if (leitura2 == HIGH && lastRead == LOW) {
      tempo = millis();
      lastRead = HIGH;
    }

    if (leitura2 == HIGH && lastRead == HIGH) {
      while (digitalRead(2)) {
        if ((millis() - tempo) > 1000) {
          while (digitalRead(2)) {
          }
          segurou = 1;
          configuracao = 0;
          lcd.setCursor(11, 1); //limpa texto alarm
          lcd.print("     ");
          lcd.setCursor(15, 0); //limpa "S"
          lcd.print("  ");
          lcd.noCursor();     //tira cursor
          if (opcao != 4) {
            dia = diaConf;
            mes = mesConf;
            ano = anoConf;
            segundo = segundoConf;
            minuto = minutoConf;
            hora = horaConf;
          }
          opcao = 1;
          Serial.println("segurou");
          attachInterrupt(digitalPinToInterrupt(2), configMode1, FALLING );
        }
      }
    }

    if (digitalRead(2) == LOW && lastRead == HIGH && !segurou) {
      switch (opcao) {
        case 1:                //hora
          horaConf++;
          if (horaConf > 23)
            horaConf = 0;
          clockUpdateConf;
          break;
        case 2:                //minuto
          minutoConf++;
          if (minutoConf > 59)
            minutoConf = 0;
          clockUpdateConf;
          break;
        case 3:                //segundo
          segundoConf++;
          if (segundo > 59)
            segundoConf = 0;
          clockUpdateConf;
          break;
        case 5:               //dia
          diaConf++;
          if ( ((mesConf == 1 || mesConf == 3 || mesConf == 5 || mesConf == 7 || mesConf == 8 || mesConf == 10 || mesConf == 12) && diaConf > 31) || ( (mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && diaConf > 30) || ( (mes == 2) && diaConf > 28) )
            diaConf = 1;
          dataUpdateConf;
          break;
        case 6:               //mes
          mesConf++;
          if (mesConf > 12)
            mesConf = 1;
          dataUpdateConf;
          break;
        case 7:               //ano
          anoConf++;
          dataUpdateConf;
          break;
        case 8:               // alarme
          if (!alarm) {
            segundoAlarm = segundoConf;
            minutoAlarm = minutoConf;
            horaAlarm = horaConf;
            alarm = 1;
            lcd.setCursor(13, 0);
            lcd.write(2);
          }
          else {
            alarm = 0;
            lcd.setCursor(13, 0);
            lcd.print("  ");
          }
          break;
      }
      Serial.println("Apertou");
    }

    lastRead = LOW;
    segurou = 0;
  }
  else {
    if (alarm && segundoAlarm == segundo && minutoAlarm == minuto && horaAlarm == hora ) {
      digitalWrite(4, HIGH);
      alarmActivate = 1;
    }
    if (alarmActivate && digitalRead(3) == HIGH) {
      digitalWrite(4, LOW);
      alarmActivate = 0;
      alarm = 0;
    }

    if (digitalRead(3) == HIGH) {
      while (digitalRead(3)) {
      }
      opcao++;
      if (opcao > 2) {
        opcao = 1;
      }
    }
    switch (opcao) {
      case 1:
        clockUpdate;
        dataUpdate;
        break;
      case 2:
        clockAlarm;
        break;
    }
  }
}
