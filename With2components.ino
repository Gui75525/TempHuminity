#include <DHT11.h>
#include <LiquidCrystal.h>

DHT11 dht11(8);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int digitalPin = 2;  // KY-028 digital interface
int analogPin = A0;  // KY-028 analog interface
int digitalVal;      // digital readings

void setup() {
  pinMode(digitalPin, INPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  int temperature = 0;
  int humidity = 0;
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  digitalVal = digitalRead(digitalPin);
  Serial.print("Digital Value : ");
  Serial.println(digitalVal);

  int v_input = 1023 - analogRead(analogPin);
  float b = 10000 * (1024.0 / (float)v_input - 1.0);
  float c = (1.0 / (0.001129148 + (0.000234125 * log(b)) + 0.0000000876741 * log(b) * log(b) * log(b))) - 273.15;

  Serial.print("Temperature in Celsius: ");
  Serial.println(c);
  
  delay(2000);

  if (result == 0) {
    lcd.clear();  

    lcd.setCursor(0, 0);
    lcd.print("TEMP:");
    lcd.print(temperature);  
    lcd.print(" C ");
    lcd.print(c, 1);  
    lcd.print(" C");
    

    lcd.setCursor(0, 1);
    lcd.print("HUM:");
    lcd.print(humidity);
    lcd.print("%  ");  
  } else {
    Serial.println(DHT11::getErrorString(result));
  }
}
