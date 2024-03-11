const int sensorPin = A1;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Nilai kelembapan tanah: ");
  Serial.println(sensorVal);
  
  if (sensorVal >= 1000) (Serial.print("SOIL IS TOO DRY!!!!!"));
  else if ((sensorVal <= 999) && (sensorVal >=901)) (Serial.print("SOIL IS PERFECT!!!!!"));
  else if (sensorVal <= 900) (Serial.print("SOIL IS TOO WET!!!!!"));
  else;
    
  delay(1000);
}