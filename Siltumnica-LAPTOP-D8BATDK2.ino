#include <dht.h>
dht DHT;
#define DHT11_PIN A2
int LED = 3;
int suknis = 4;
int blueLED = 8;
int greenLED = 9;
int redLED = 10;
int yellowLED = 11;
int zemesMitrumaSensors = A1;
int zemesMitrumaVertiba;
int gaismasSensors = A0;
int gaismasSensoraVertiba;
int zemesMitrumaRobeza = 700;

void setup() {  
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(suknis,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperatūra siltumnīcā = ");
  Serial.print(DHT.temperature);
  Serial.println(" °C");
  Serial.print("Gaisa mitrums siltumnīcā = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");
  
  if(DHT.temperature <= 10){   
    digitalWrite(blueLED,HIGH);
  }
  else{
    digitalWrite(blueLED,LOW);
  }
  
  if(DHT.temperature > 10 && DHT.temperature < 27){
    digitalWrite(greenLED,HIGH);
  }
  else{
    digitalWrite(greenLED,LOW);
  }
  
  if(DHT.temperature >= 27){
    digitalWrite(redLED,HIGH);
  }
  else{
    digitalWrite(redLED,LOW);
  }
  
  if(DHT.humidity > 70){
    digitalWrite(yellowLED,HIGH);
  }
  else{
    digitalWrite(yellowLED,LOW);
  }

  zemesMitrumaVertiba = analogRead(zemesMitrumaSensors);
  Serial.print("Zemes mitruma vērtība: ");
  Serial.println(zemesMitrumaVertiba);
  if(zemesMitrumaVertiba > zemesMitrumaRobeza){
    digitalWrite(suknis,LOW);
  }
  if(zemesMitrumaVertiba <= zemesMitrumaRobeza){
    digitalWrite(suknis,HIGH);
  }
  
  gaismasSensoraVertiba = analogRead(gaismasSensors);
  Serial.print("Gaismas sensora vērtība: ");
  Serial.println(gaismasSensoraVertiba);
  if(gaismasSensoraVertiba < 30){
    analogWrite(LED,200);
  }
  else{
    analogWrite(LED,0);
  }
  
  Serial.println("____________________________________________________");
  delay(5000);
}
