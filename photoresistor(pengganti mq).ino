#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int photoresistorPin = 2;
const int ledGreenPin = 5;
const int ledRedPin = 3;
int lightIntensity;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(photoresistorPin, INPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);


  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Light Intensity:");
  

  Serial.begin(9600);
}

void loop() {

  lightIntensity = digitalRead(photoresistorPin);

  lcd.setCursor(0, 1);
  lcd.print("Intensity: ");
  lcd.print(lightIntensity);

  Serial.println(lightIntensity);

  if (lightIntensity == HIGH) {
    digitalWrite(ledGreenPin, HIGH);
    digitalWrite(ledRedPin, LOW);
  }else {
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledRedPin, HIGH);
  }

  delay(500);
}
