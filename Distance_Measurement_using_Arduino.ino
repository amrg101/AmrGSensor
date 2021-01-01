#include <Wire.h>
#include <LiquidCrystal.h>              //بنعمل استيراد للمكتبات ال هنستخدمها
LiquidCrystal lcd(0LiquidCrystal lcd(7, 8, 9, 10, 11, 12);x27, 16,2);   //بنحدد هنربط الشاشه فين ف الاردوينو
const int trigPin = 3;
const int echoPin = 2;                    
long duration;
int distanceCm, distanceInch;            // بنعمل تعريف للمتغيرات و بنربط البين بالتريج والايكو
void setup() {
  lcd.init();
  lcd.begin(16, 2);                      // Initializes the interface to the LCD display
  lcd.clear();
  lcd.backlight();                       //بنصطب ال lcd 
  pinMode(trigPin, OUTPUT);              // بنحددالمدخلات والمخرجات
  pinMode(echoPin, INPUT);
  Serial.begin(9600);                   //هنا بنحدد معدل سرعة نقل البيانات 
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
  lcd.setCursor(0, 0);                  //بنحدد الطباعه هتبقا فين على الشاشه
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(1000);
  lcd.clear();
}
