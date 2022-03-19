#include <DHT.h>
// include the library code:
#include <LiquidCrystal.h>

#define DHT11PIN 3
#define DHTTYPE DHT11

DHT dht(DHT11PIN, DHTTYPE);
float h,tc,tf;

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  delay(200);
  Serial.begin(9600);
  dht.begin();
  delay(1000);
  Serial.println("DHT11 Temperature and Humidity ");

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
//  lcd.print("test, world!");
}

void loop()
{
  
  delay(2000);
  h = dht.readHumidity();
  delay(2000);
  tc = dht.readTemperature();
  delay(2000);
  tf = dht.readTemperature(true);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hum:"+ String(h)+"%");
  lcd.setCursor(0, 1);
  lcd.print("Temp:"+ String(tc)+"C");
  
  
  Serial.print('\n');
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.print("%,  ");
  Serial.print("Temperature = ");
  Serial.print(tc);
  Serial.print("°C, ");
//  Serial.print(tf);
//  Serial.println("°F");
}