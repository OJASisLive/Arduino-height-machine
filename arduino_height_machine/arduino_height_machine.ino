#define echoPin 6
#define trigPin 7

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


long duration; 
int distance; 

float foot;
int ifoot;
float remainder;
int inches;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);

  lcd.begin(16, 2);
}
void loop() {

  delay(1000);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = 200 - (duration * 0.034 / 2);

  foot = distance/30.48;
  ifoot = distance/30.48;
  remainder = foot - ifoot;
  inches = remainder * 12;
  Serial.print("Height: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print(ifoot);
  Serial.print("'");
  Serial.print(inches);
  Serial.println('"');

  lcd.setCursor(0, 0);
  lcd.print("Height: ");
  //lcd.setCursor(9,0);
  lcd.print(distance);
  //lcd.setCursor(13,0);
  lcd.print(" cm ");
  lcd.setCursor(0,1);
  lcd.print(ifoot);
  //lcd.setCursor(1,1);
  lcd.print("'");
  //lcd.setCursor(3,1);
  lcd.print(inches);
  //lcd.setCursor(5,1);
  lcd.print('"');
  lcd.print("feet & inch ");
}
