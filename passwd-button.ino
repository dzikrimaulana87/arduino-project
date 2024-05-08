#include <ESP32Servo.h>

const int btnRedPin = 2;
const int btnGreenPin = 3;
const int btnBluePin = 1;
const int btnYellowPin = 0;


const int servoPin = 9;
const int buzzerPin = 10;


const int password[] = {1, 2, 3, 4};
const int passwordLength = 4;

int enteredPassword[] = {0, 0, 0, 0};
int enteredLength = 0;

Servo servo;
bool isServoOpen = false;
unsigned long servoOpenTime = 0;
const unsigned long servoOpenDuration = 5000;

void setup() {
  pinMode(btnRedPin, INPUT_PULLUP);
  pinMode(btnGreenPin, INPUT_PULLUP);
  pinMode(btnBluePin, INPUT_PULLUP);
  pinMode(btnYellowPin, INPUT_PULLUP);

  servo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {

  if (digitalRead(btnRedPin) == LOW) {
    addPassword(1);
    delay(500);
  }
  if (digitalRead(btnGreenPin) == LOW) {
    addPassword(2);
    delay(500);
  }
  if (digitalRead(btnBluePin) == LOW) {
    addPassword(3);
    delay(500);
  }
  if (digitalRead(btnYellowPin) == LOW) {
    addPassword(4);
    delay(500);
  }

  if (isServoOpen && millis() - servoOpenTime >= servoOpenDuration) {
    closeServo();
  }
}

void addPassword(int digit) {
  if (enteredLength < passwordLength) {
    enteredPassword[enteredLength] = digit;
    enteredLength++;
    for (int i = 0; i < enteredLength; i++) {
      Serial.print(enteredPassword[i]);
    }
    Serial.println();
    checkPassword();
  } else {
    resetPassword();
  }
}

void checkPassword() {
  if (enteredLength == passwordLength) {
    bool isCorrect = true;
    for (int i = 0; i < passwordLength; i++) {
      if (enteredPassword[i] != password[i]) {
        isCorrect = false;
        break;
      }
    }
    if (isCorrect) {
      openServo();
      Serial.println("Password Benar");
      servoOpenTime = millis();
    } else {
      tone(buzzerPin, 1000);
      resetPassword();
      Serial.println("Password Salah");
    }
  }
}

void resetPassword() {
  enteredLength = 0;
  for (int i = 0; i < passwordLength; i++) {
    enteredPassword[i] = 0;
  }
}

void openServo() {
  if (!isServoOpen) {
    servo.write(180);
    isServoOpen = true;
  }
}

void closeServo() {
  if (isServoOpen) {
    servo.write(90);
    isServoOpen = false;
  }
}
