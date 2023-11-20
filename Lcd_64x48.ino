#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>  
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define SCREEN_WIDTH 128 // OLED display ancho, en pixels
#define SCREEN_HEIGHT 64 // OLED display largo, en pixels
#define OLED_RESET 0
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);  
#define DHTPIN 2     

#define BLUE 0x001F
#define DHTTYPE    DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
 // display.begin(SH1106_SWITCHCAPVCC, 0x3C);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
 //  display.setTextColor(BLUE);
}

void loop() {
  delay(2000);

  //read temperature and humidity
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) {
    Serial.println("Fallo!");
  }
Serial.println(t);
Serial.println(h);
  //clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,7);
  //display.setTextColor(BLUE);
display.setTextSize(1);
  display.setCursor(35, 15);
  display.print("Humedad: ");
  display.setTextSize(1);
  display.setCursor(35, 25);
  display.print(h);
  display.print(" %"); 
  display.display();

  
  // display humidity
  display.setTextSize(1);
  display.setCursor(35, 35);
  display.print("Temperat: ");
  display.setTextSize(1);
  display.setCursor(35, 45);
  display.print(t);
  display.print(" C"); 
  display.display(); 
}
