

#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.my address is (0x3F)

int trigPin = A0;
int echoPin = A1;

long distance;
long distanceInch;
long duration;

void setup(){
 lcd.init();
 lcd.backlight();
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 lcd.setCursor(0,0);
 lcd.print("   WELCOME TO");
 lcd.setCursor(0,1);
 lcd.print("  MKINVENTIONS");
 delay(2000);
}

void loop() {
 ULTRASONIC();
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("DISTANCE CM:");
 lcd.print(distance); 
 lcd.setCursor(0,1);
 lcd.print("DISTANCE INCH:");
 lcd.print(distanceInch); 

// lcd.setCursor(0,1);   
// lcd.print("DISTANCE MM:");
// lcd.print(distanceInch); 
}

void ULTRASONIC(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  distanceInch = duration*0.0133/2;
} 
