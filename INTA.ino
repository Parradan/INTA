#include "DHT.h"

#define DHT2PIN 2     // PIN CONECTADO
#define DHT3PIN 3     // PIN CONECTADO  
#define DHT4PIN 4     // PIN CONECTADO
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define temp 5000


DHT dht1(4, DHT22);
DHT dht2(2, DHT22);
DHT dht3(3, DHT22);

void setup() {
 Serial.begin(9600);
 Serial.println("CLEARSHEET"); 
 Serial.println("CLEARSDATA"); 
 Serial.println("LABEL,FECHA,HORA,TIMER(SEG),T1 (C), H1 (%),T2 (C),H2 (%),T3 (C),H3 (%)"); 
 Serial.println("RESETTIMER"); 

 dht1.begin();
 dht2.begin();
 dht3.begin();
}

void loop() {
        
  float H1 = dht1.readHumidity();
  float T1 = dht1.readTemperature();
  //Serial.println(H1);
  //Serial.println(T1);
  float H2 = dht2.readHumidity();
  float T2 = dht2.readTemperature();
 //Serial.println(H2);
 // Serial.println(T2);
  float H3 = dht3.readHumidity();
  float T3 = dht3.readTemperature();
 // Serial.println(H3);
  //Serial.println(T3);
  float promhum=0;
  float promtemp=0;
//    promhum=(H1+H2+H3)/3;
//    promtemp=(T1+T2+T3)/3;
    H1=H1+3.1;
    H2=H2-2.2;
    H3=H3-1.1;
    T1=T1+0.15;
    T2=T2-0.15;
    T3=T3-0.05;
//  Serial.println(T1);
//  Serial.println(T2);
//  Serial.println(T3);
//  Serial.println(H1);
//  Serial.println(H2);
//  Serial.println(H3);
  Serial.print("DATA,DATE,TIME,TIMER,");Serial.print(T1);Serial.print(",");Serial.print(H1);Serial.print(",");Serial.print(T2);Serial.print(",");Serial.print(H2);Serial.print(",");Serial.print(T3);Serial.print(",");Serial.println(H3);
  delay(temp);
 }
