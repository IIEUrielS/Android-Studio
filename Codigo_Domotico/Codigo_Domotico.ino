#include <WiFi.h>
#include <FirebaseESP32.h>
#include "DHT.h"

#define ssid "Totalplay-66A3"       //WiFi SSID
#define pass "66A3AFF9QW2tYHPE"    //WiFi Password
//const char* ssid     = "your-ssid";
//const char* password = "your-password";

#define led1 2
#define led2 32
#define led3 13

#define led4 22
#define led5 23
#define led6 33


#define URL "cesp32-a76b8-default-rtdb.firebaseio.com"
#define secreto "VXERzAnI8aO2FKB0z4VzVxsJuwabzozS2HO7DPVN" 

FirebaseData myFireBaseData;
FirebaseJson myJson;
FirebaseJsonData myJsonData;

String estados, estado1, estado2, estado3, estado4, estado5, estado6, estado7, estado8, estado9;
int intervalo = 10000;
unsigned long actual = 0, ultimo = 0;
float T,H;
DHT dht(4, DHT11);

void setup() 
{
  Serial.begin(115200);
  dht.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  digitalWrite(led3, 0);
  Serial.print("Conectado a la red: ");
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED)
  {
   Serial.print(".");
   delay(500);
  }
  Firebase.begin(URL, secreto);
  Firebase.reconnectWiFi(true);
  Serial.println("Conectado con exito");
}

void loop() 
{
 actual = millis();
 if(actual - ultimo >= intervalo)
 {
  ultimo = actual;
  T = dht.readTemperature();
  H = dht.readHumidity();
  Firebase.set(myFireBaseData,"/LECTURAS/temp",T);
  Firebase.set(myFireBaseData,"/LECTURAS/hum",H);
    Serial.print("temp=");
  Serial.println(T);
    Serial.print("Humedad:");
  Serial.println(H);
 }
 //================================================
 //=====================Salida 1===================
 //================================================
 Firebase.get(myFireBaseData, "/BOTONLED1");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado1 = myJsonData.stringValue;
 //Serial.println(estado1);
 
 //================================================
 //=====================Salida 2===================
 //================================================
 Firebase.get(myFireBaseData, "/BOTONLED2");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 //myJson.setJsonData(myFireBaseData.jsonString());
 myJson.get(myJsonData, "/Valor");
 estado2 = myJsonData.stringValue;
 // Serial.println(estado2);
 //================================================
 //=====================Salida 3===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED3");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado3 = myJsonData.stringValue;
 //Serial.println(estado1);
 //================================================
 //=====================Salida 4===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED4");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado4 = myJsonData.stringValue;
 //Serial.println(estado1);
//================================================
 //=====================Salida 5===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED5");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado5 = myJsonData.stringValue;
 //Serial.println(estado1);
//================================================
 //=====================Salida 6===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED6");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado6 = myJsonData.stringValue;
 //Serial.println(estado1);
//================================================
 //=====================Salida 7===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED7");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado7 = myJsonData.stringValue;
 //Serial.println(estado1);
 //================================================
 //=====================Salida 8===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED8");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado8 = myJsonData.stringValue;
 //Serial.println(estado1);
 //================================================
 //=====================Salida 9===================
 //================================================
  Firebase.get(myFireBaseData, "/BOTONLED9");
 estados = myFireBaseData.jsonString();
 myJson.setJsonData(estados);
 myJson.get(myJsonData, "/Valor");
 estado9 = myJsonData.stringValue;
 //Serial.println(estado1);




 
 //================================================
 //================Acciones a ejecutar=============
 //================================================
 if(estado1 == "true"){digitalWrite(led1, 1);}
 else{digitalWrite(led1, 0);}

 if(estado2 == "true"){digitalWrite(led2, 1);}
 else{digitalWrite(led2, 0);}

 if(estado3 == "true"){digitalWrite(led3, 1);}
 else{digitalWrite(led3, 0);}

 if(estado4 == "true"){digitalWrite(led4, 1);}
 else{digitalWrite(led4, 0);}

 if(estado5 == "true"){digitalWrite(led5, 1);}
 else{digitalWrite(led5, 0);}

if(estado6 == "true"){digitalWrite(led6, 1);}
 else{digitalWrite(led6, 0);}



  
}

