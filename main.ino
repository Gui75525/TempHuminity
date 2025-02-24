#include <DHT11.h>
#include <LiquidCrystal.h>


DHT11 dht11(8);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {

    Serial.begin(9600);

    lcd.begin(16, 2);
    lcd.clear();
}

void loop() {
    int temperature = 0;
    int humidity = 0;


    int result = dht11.readTemperatureHumidity(temperature, humidity);


    if (result == 0) {
        lcd.print("TEMP:");
        lcd.print(temperature);
        lcd.print(" C");
        lcd.setCursor(0, 1);
        lcd.print("HUM:");
        lcd.print(humidity);
        lcd.println(" %        ");
    } else {
        Serial.println(DHT11::getErrorString(result));
    }
}
