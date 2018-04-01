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
  //  Serial.println("!");
    // put your main code here, to run repeatedly:
    analogButton->update(millis());

    int keyPres = analogButton->isPressed();

  //  Serial.println(keyPres);
    switch (keyPres) {
        case 1: Serial.println("+");
            break;
        case 2: Serial.println("-");
            break;
        case 3: Serial.println("sel");
            break;
        default:
            break;
    }
    delay(1000);
}
