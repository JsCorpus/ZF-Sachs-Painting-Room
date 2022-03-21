#include <ESP8266WiFi.h>
const char* ssid     = "Totalplay-DA7C";      // SSID
const char* password = "DA7C67DAnraU27Sr";      // Password
const char* host = "zf-painting-room.000webhostapp.com";  // IP o dirección del servidor intermedio
const int   port = 80;            // Puerto del server
const int   watchdog = 5000;        // Frecuencia de Whatchdog
unsigned long previousMillis = millis(); 


#include "DHT.h"        // Librería de DTH11
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 5 //Corresponde al pin D1
DHT dht(dht_dpin, DHTTYPE); 

//Declaramos la salida de 5v de la alarma externa
const int LED1 = 4; //Corresponde al pin D2
const int LED2 = 0; //Corresponde al pin D3
const int LED3 = 2; //Corresponde al pin D4
const int LED4 = 14; //Corresponde al pin D5
const int LED5 = 12; //Corresponde al pin D6

//Declaramos el pin que activará la alarma sonora con 5v
const int Sound = 13; //Corresponde al pin D7

//Declaramos el LED que indicará el fallo de conexión
const int Warning = 15; //Corresponde al pin D8

void setup(void)
{ 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("¡Conectado al WI-FI!");  
  Serial.println("IP asignada: ");
  Serial.println(WiFi.localIP());
  
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humedad y Temperatura\n\n");
  delay(700);

  //Establecemos los pines de salida
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(Sound , OUTPUT);
  pinMode(Warning , OUTPUT);

}
void loop() {
    //Declaramos las variables de información
    String tempid = "";
    String humid = "";

    //Variable contador de tiempo offline
    int tim = 0;

    //Variable contador de tiempo en error
    int timer = 0;
  
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Humedad = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("Temperatura = ");
    Serial.print(t); 
    Serial.println("°c  ");

  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error");
    timer++;
    tim++;
    return;
  }
  
    unsigned long currentMillis = millis();
    
  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    WiFiClient client;
  
    if (!client.connect(host, port)) {
      Serial.println("Fallo al conectar");
      digitalWrite(Warning, HIGH);
      tim++;
      return;
    } else {
      digitalWrite(Warning, LOW);
    }


//Alarmas
    if(h >= 40 || t >= 35){
    LEDS();
    Serial.println("Warning");  
    } else {
    Serial.println("Nice");
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(Sound, LOW);
    }

//Selector de mensaje de información (Temperatura ideal - Alta tolerable - Temperatura alta

  if( t >= 24 && t <= 32){
    tempid = "Alta tolerable";
  } else if 
  ( t >= 33 ){
    tempid = "Temperatura alta";
  } else {
    tempid = "Temperatura ideal";
  }

  //Selector de mensaje de información (humedad ideal - Alta tolerable - Temperatura alta

  if( h >= 27 && h <= 29){
    humid = "Alta tolerable";
  } else if 
  ( h >= 30 ){
    humid = "Temperatura alta";
  } else {
    humid = "Humedad ideal";
  }

    String url = "/Firebase.php?temperatura=";
    url += t;
    url += "&humedad=";
    url += h;
    url += "&tempid=";
    url += tempid;
    url += "&humid=";
    url += humid;
    url += "&tim=";
    url += tim;
    url += "&timer=";
    url += timer;
    
    
    // Enviamos petición al servidor
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: keep-alive\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
  
    // Leemos la respuesta del servidor
    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  }
  delay(800);
}

//Función que enciende los LEDS
void LEDS(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(Sound, HIGH);
}