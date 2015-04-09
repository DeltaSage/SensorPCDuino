/*
Author:          Brian Dignam
Date Created:    3/1/2015
*/


#include "DHT.h"

#define DHTPIN A0
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

#define MQ2PIN A3

int TIMESTAMP;

void setupDHT()
{  
  dht.begin();
}

void setup() 
{
    Serial.begin(9600); 
    Serial.println("Serial Connection Established");
    
    TIMESTAMP = 0;
    
    setupDHT();
}

float getHumidity()
{
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
  float h = dht.readHumidity();
  
  if (!isnan(h))
    return h;
  else
    return 0.0;
    
}

float getTemp()
{
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
  float t = dht.readTemperature();
  
  if (!isnan(t))
    return t;
  else
    return 0.0;
    
}

float getMQ2Gas()
{
  float vol;
  int sensorValue = analogRead(MQ2PIN);
  vol=(float)sensorValue/1024*5.0;
  //Serial.println(vol,1);
  
  return vol;
}

void loop() 
{
  Serial.print("Timestamp:  ");
  Serial.println(TIMESTAMP);
  Serial.println();
  
  Serial.print("Temp:  ");
  Serial.println(getTemp());
  
  Serial.print("Humidity:  ");  
  Serial.println(getHumidity() );
  
  Serial.print("MQ2 Gas:  ");
  Serial.println(getMQ2Gas(),1);
  
  
  
  Serial.println();  
  TIMESTAMP++;
  delay(2000);  //2s
}
