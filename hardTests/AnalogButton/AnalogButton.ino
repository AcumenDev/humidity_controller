#include "AnalogButton.hpp"
#define CLIMATE_DEBUG
AnalogButton *analogButton;
void setup() {
    Serial.begin(9600);
    Serial.println("setup");
    // put your setup code here, to run once:
    Key keys[3] = {Key(1, 100, 200), Key(2, 200, 400), Key(3, 600, 800)};
    pinMode(A0, INPUT);
    analogButton = new AnalogButton(A0, keys, 3);
    Serial.println("setup");
}

void loop() {

///left 480
///right 0
//up 131
//down 306
//sel 721

  
  //  Serial.println("!");
    // put your main code here, to run repeatedly:

    Serial.println(analogRead(A0));
   // analogButton->update(millis());

 //   int keyPres = analogButton->isPressed();

  //  Serial.println(keyPres);
 //   switch (keyPres) {
  //      case 1: Serial.println("+");
 //           break;
 //       case 2: Serial.println("-");
 //           break;
 //       case 3: Serial.println("sel");
 //           break;
  //      default:
 //           break;
 //   }
   // delay(1000);
}
