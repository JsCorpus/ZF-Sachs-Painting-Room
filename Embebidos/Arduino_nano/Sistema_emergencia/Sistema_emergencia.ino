// Incluimos librería
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Declaramos el tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

//Declaramos el led para comprobar la conexion de Android al Arduino
const int UserConnected = 7;
//Declaramos el pin que activará la bocina
const int Sound = 6;

//Declaramos una variable de cambio
int change = 0;

//Declaramos los LED de la alarma sonora
const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;
const int LED4 = 8;
const int LED5 = 10;
const int LED6 = 11;
  
//Declaramos una variable global que almacenará los datos de Android
char Kotlin;

//Declaramos las variables de la alarma sonora
float sinVal;
int toneVal;



 
void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();

    //Definimos un pin como salida
  pinMode(UserConnected, OUTPUT);
  pinMode(Sound, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}




void loop() {
    // Esperamos 5 segundos entre medidas
    //delay(500);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();

 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error");
    return;
  }

  //Método para hacer acción esperando un caracter
  if(Serial.available()>0){
    digitalWrite(UserConnected, HIGH);
  Kotlin=Serial.read();
  if(Kotlin == '0'){
    for(int x=0; x<180; x++){
            // convertimos grados en radianes para luego obtener el valor.
            sinVal = (sin(x*(3.1412/180)));
            // generar una frecuencia a partir del valor sin
            toneVal = 2000+(int(sinVal*1000));
            tone(Sound, toneVal);
            delay(2); 
     } 
      delay(5000);
      noTone(Sound);
    } else if
    (Kotlin == '3'){
      LEDS2();
    }
  } else {
    digitalWrite(UserConnected, LOW);
  }

  if(h >= 40 || t >= 35){
     for(int x=0; x<180; x++){
            // convertimos grados en radianes para luego obtener el valor.
            sinVal = (sin(x*(3.1412/180)));
            // generar una frecuencia a partir del valor sin
            toneVal = 2000+(int(sinVal*1000));
            tone(Sound, toneVal);
            delay(2); 
     } 
  } else {
     noTone(Sound);
     digitalWrite(2, LOW);
     }

if(h >= 40 || t >= 35){
  LEDS();
}

 //Mandar los datos entre datos rápidos y/o lentos
 if(h>= 40 && t>=35){
  Slow();
 }else if
 (h >= 40){
  fasth();
 }else if
 (t>=35){
  fastt();
 } else{
  Slow();
 }
}

//Declaramos una función que mandará los datos de manera lenta
void Slow(){
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
   if(change == 0){
  Serial.print(t);
  Serial.println("°c");
  change++;
  delay(500);
  }
  else{
   Serial.print(h);
   Serial.println("%"); 
  change--;
  delay(500);
  }
}

//Declaramos una función que mandará los datos de manera lenta
void Slow2(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
   if(change == 0){
  Serial.print(t);
  Serial.println("°c");
  change++;
  delay(500);
  }
  else{
   Serial.print(h);
   Serial.println("%"); 
  change--;
  delay(500);
  }
}

void fastt(){
  float t = dht.readTemperature();
  Serial.print(t);
  Serial.println("°c");
  delay(500);
}

void fasth(){
  float h = dht.readHumidity();
  Serial.print(h);
  Serial.println("%");
  delay(500); 
}

void LEDS(){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW); 
}

void LEDS2(){
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(200);
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(200);
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(200);
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(200);
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(200);
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(200);
      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      delay(100);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      delay(100);
      digitalWrite(LED6, LOW);
      delay(100);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(500);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay (500);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(500);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(500);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
}
