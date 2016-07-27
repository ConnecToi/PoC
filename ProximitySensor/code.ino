/*************************************************
    Public Constants Pins
  *************************************************/
#define trigPin 7
#define echoPin 6
#define led 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define buzzer 3
#define sensorPin 0

/*************************************************
    Public Constants notes
  *************************************************/
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

int sound = 250;
int speakerPin = buzzer;
void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
  march();
}
void newbeep(unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{
  int randNumber = random(8, 13);
  digitalWrite(randNumber, HIGH);
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (x = 0; x < loopTime; x++)
  {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(delayAmount);
  }
  digitalWrite(randNumber, LOW);
  delay(20);
}

void march()
{
  newbeep(speakerPin, a, 500);
  newbeep(speakerPin, a, 500);
  newbeep(speakerPin, a, 500);
  newbeep(speakerPin, f, 350);
  newbeep(speakerPin, cH, 150);
  newbeep(speakerPin, a, 500);
  newbeep(speakerPin, f, 350);
  newbeep(speakerPin, cH, 150);
  newbeep(speakerPin, a, 1000);
  newbeep(speakerPin, eH, 500);
  newbeep(speakerPin, eH, 500);
  newbeep(speakerPin, eH, 500);
  newbeep(speakerPin, fH, 350);
  newbeep(speakerPin, cH, 350);
  newbeep(speakerPin, gS, 500);
  newbeep(speakerPin, f, 350);
  newbeep(speakerPin, cH, 150);
  newbeep(speakerPin, a, 1000);
  newbeep(speakerPin, aH, 500);
  newbeep(speakerPin, a, 350);
  newbeep(speakerPin, a, 150);
  newbeep(speakerPin, aH, 500);
  newbeep(speakerPin, gSH, 250);
  newbeep(speakerPin, gH, 250);
  newbeep(speakerPin, fSH, 125);
  newbeep(speakerPin, fH, 125);
  newbeep(speakerPin, fSH, 250);
  delay(250);
  newbeep(speakerPin, aS, 250);
  newbeep(speakerPin, dSH, 500);
  newbeep(speakerPin, dH, 250);
  newbeep(speakerPin, cSH, 250);
  newbeep(speakerPin, cH, 125);
  newbeep(speakerPin, b, 125);
  newbeep(speakerPin, cH, 250);
  delay(250);
  newbeep(speakerPin, f, 125);
  newbeep(speakerPin, gS, 500);
  newbeep(speakerPin, f, 375);
  newbeep(speakerPin, a, 125);
  newbeep(speakerPin, cH, 500);
  newbeep(speakerPin, a, 375);
  newbeep(speakerPin, cH, 125);
  newbeep(speakerPin, eH, 1000);
  newbeep(speakerPin, aH, 500);
  newbeep(speakerPin, a, 350);
  newbeep(speakerPin, a, 150);
  newbeep(speakerPin, aH, 500);
  newbeep(speakerPin, gSH, 250);
  newbeep(speakerPin, gH, 250);
  newbeep(speakerPin, fSH, 125);
  newbeep(speakerPin, fH, 125);
  newbeep(speakerPin, fSH, 250);
  delay(250);
  newbeep(speakerPin, aS, 250);
  newbeep(speakerPin, dSH, 500);
  newbeep(speakerPin, dH, 250);
  newbeep(speakerPin, cSH, 250);
  newbeep(speakerPin, cH, 125);
  newbeep(speakerPin, b, 125);
  newbeep(speakerPin, cH, 250);
  delay(250);
  newbeep(speakerPin, f, 250);
  newbeep(speakerPin, gS, 500);
  newbeep(speakerPin, f, 375);
  newbeep(speakerPin, cH, 125);
  newbeep(speakerPin, a, 500);
  newbeep(speakerPin, f, 375);
  newbeep(speakerPin, c, 125);
  newbeep(speakerPin, a, 1000);
}
void proximity()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance <= 90) {
    digitalWrite(led, HIGH);
    sound = 10;
  }
  else {
    digitalWrite(led, LOW);
  }
  if (distance < 75) {
    digitalWrite(led2, HIGH);
    sound = 260;
  }
  else {
    digitalWrite(led2, LOW);
  }
  if (distance < 60) {
    digitalWrite(led3, HIGH);
    sound = 270;
  }
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 45) {
    digitalWrite(led4, HIGH);
    sound = 280;
  }
  else {
    digitalWrite(led4, LOW);
  }
  if (distance < 30 ) {
    digitalWrite(led5, HIGH);
    sound = 290;
  }
  else {
    digitalWrite(led5, LOW);
  }
  if (distance < 15) {
    digitalWrite(led6, HIGH);
    sound = 300;
  }
  else {
    digitalWrite(led6, LOW);
  }
  if (distance > 90 || distance <= 0) {
    Serial.println("Out of range");
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
  }
  delay(50);
}

void temp()
{
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  Serial.print(voltage);
  Serial.println(" volts");
  float temperatureC = (voltage - 0.5) * 100 ;
  Serial.print(temperatureC);
  Serial.println(" degrees C");
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.println(" degrees F");
  delay(1000);
}
void loop()
{
  proximity();
  temp();
}
