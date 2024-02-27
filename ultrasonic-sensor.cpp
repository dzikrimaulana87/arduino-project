#include <NewPing.h>
#include <TimeLib.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 310

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int previousDistance = 0;

void setup() {
  Serial.begin(9600);
  setTime(0, 0, 0, 1, 1, 2024);
}
void loop() {
  delay(1000);
  unsigned int distance = sonar.ping_cm();
  Serial.print("Jarak = ");
  Serial.print(distance);
  Serial.print(" cm");

  if (distance < previousDistance) {
    Serial.println(" << Mendekat");
  } else if (distance > previousDistance) {
    Serial.println(" >> Menjauh");
  } else {
    Serial.println(" = Tidak berubah");
  }
  previousDistance = distance;
  
  Serial.print("Waktu: ");
  printDigits(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits) {
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
