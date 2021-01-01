#include <Wire.h>
#include <LiquidCrystal.h>              
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);    //LCD object Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 12;
const int echoPin = 11;                    
long duration;
int distanceCm, distanceInch;            
void setup() {
  lcd.init();
  lcd.begin(16, 2);                      // Initializes the interface to the LCD display
  lcd.clear();
  lcd.backlight();                       
  pinMode(trigPin, OUTPUT);              
  pinMode(echoPin, INPUT);
  Serial.begin(9600);                  
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0340 / 2;
  distanceInch = duration * 0.01330 / 2;
  lcd.setCursor(0, 0);                  
  lcd.clear();
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(1000);
}
