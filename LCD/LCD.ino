
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define POWER_PIN  7
#define SIGNAL_PIN A3

int value=0;


void setup()
{
  Serial.begin(2 * 9600);
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);  // top line of display
  lcd.print("Water Level:");
}



void loop()
{
  // Raise pin 7 for 10ms to power water sensor, and take a reading before powering off again
  digitalWrite(POWER_PIN, HIGH);  
  delay(10);               
  value = analogRead(SIGNAL_PIN);
  digitalWrite(POWER_PIN, LOW);  

  //Serial.print("Sensor value: ");
  //Serial.println(value);

  lcd.setCursor(0,1);   // bottom line of the display
  lcd.print("      ");  // clear line
  lcd.setCursor(0,1);
  lcd.print(value);
  
  delay(1000);  // sleep for one second
}
