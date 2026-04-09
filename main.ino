// C++ code
//

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin = 9;
const int potPin = A0;

const int updateInterval = 200;

int rawValue = 0;
int brightness = 0;

unsigned long lastUpdateTime = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("READY");
  delay(1000);
  lcd.clear();
  
  Serial.begin(9600);
}

void loop()
{
  rawValue = analogRead(potPin);
  
  brightness = map(rawValue, 0, 1023, 0, 100);
  
  analogWrite(ledPin, map(brightness, 0, 1023, 0, 255));
  
  unsigned long currentTime = millis();
  if(currentTime - lastUpdateTime >= updateInterval){
    lastUpdateTime = currentTime;
    lcd.setCursor(0, 0);
    lcd.print("Brightness:");
    lcd.print(brightness);
    lcd.print(" ");

    lcd.setCursor(0, 1);
    if(brightness > 90){
      lcd.print("CRITICAL        ");
    } else{
      lcd.print("NORMAL          ");
    }

    Serial.print("Pot Value: ");
    Serial.print(rawValue);
    Serial.print(" | Brightness Level: ");
    Serial.println(brightness);
  } 
}
