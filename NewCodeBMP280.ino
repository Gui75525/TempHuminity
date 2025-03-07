#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C

unsigned long delayTime;

void setup() {
  Serial.begin(9600);
  delay(1000); // Pequeno atraso para inicializar

  Serial.println(F("BME280 Sensor Test"));

  if (!bme.begin(0x76)) { // Garante que o endereço correto está a ser usado
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Sensor Initialized --");
  delayTime = 2000; // Atualização a cada 2 segundos
}

void loop() { 
  printValues();
  delay(delayTime);
}

void printValues() {
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F; // Convertendo para hPa

  Serial.println("===== Sensor Readings =====");
  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity, 2);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure, 2);
  Serial.println(" hPa");

  Serial.println("===========================");
  Serial.println();
}
