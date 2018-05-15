//code by codevaders on Lenovo ThinkPad T480s(YUMEMI-8G-W10)
//https://github.com/strixqlater/KM_IR_RECV

#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results result;

String convert(long int x) {
  if (x == 16753245) return "1";
  if (x == 16736925) return "2";
  if (x == 16769565) return "3";
  if (x == 16720605) return "4";
  if (x == 16712445) return "5";
  if (x == 16761405) return "6";
  if (x == 16769055) return "7";
  if (x == 16754775) return "8";
  if (x == 16748655) return "9";
  if (x == 16738455) return "*";
  if (x == 16750695) return "0";
  if (x == 16756815) return "#";
  if (x == 16718055) return "↑";
  if (x == 16716015) return "←";
  if (x == 16726215) return "OK";
  if (x == 16734885) return "→";
  if (x == 16730805) return "↓";
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if(irrecv.decode(&result)) {
    long int decCode = result.value;
    String res = convert(decCode);
    
    Serial.print("DEC: ");
    Serial.print(decCode);
    Serial.print(" ## ");
    Serial.print("HEX: ");
    Serial.print(decCode, HEX);
    Serial.print(" ## ");
    Serial.print("KEY: ");
    Serial.print(res);
    Serial.println();

    if(res == "0") {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      Serial.println("LED OFF");
    }

    if(res == "1") {
      digitalWrite(5, HIGH);
      Serial.println("LED 1 is ON");
    }

    if(res == "2") {
      digitalWrite(6, HIGH);
      Serial.println("LED 2 is ON");
    }

    if(res == "3") {
      digitalWrite(7, HIGH);
      Serial.println("LED 3 is ON");
    }
    delay(100);
    irrecv.resume();
  }
}
