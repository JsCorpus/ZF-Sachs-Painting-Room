/*CONEXIONES:
  ARDUINO   BLUETOOTH
  5V        VCC
  GND       GND
  PIN 2     TX
  PIN 3     RX
  
 */
#include <SoftwareSerial.h> //Librería para usar otros pines como puerto serie
#include <DHT.h> //Librería para usar el sensor de humedad y temperatura
#define DHTPIN 4 //Indicamos que pin usaremos para transmitir los datos del DHT
#define DHTTYPE DHT11 //Definimos que tipo de DHT utilizaremos (Cambiar a DHT22 si se sa este)
DHT dht(DHTPIN, DHTTYPE);

char Kotlin; //Declaramos una variable tipo char
SoftwareSerial blue(2, 3);   //Crea conexion al bluetooth - PIN 2 a TX y PIN 3 a RX

char NOMBRE[21]  = "Painting Room A1"; // Nombre de 20 caracteres maximo
char BPS         = '4';     // 1=1200 , 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
char PASS[5]    = "5555";   // PIN O CLAVE de 4 caracteres numericos     
 
void setup()
{
    blue.begin(9600); // Iniciamos la comunicacion serial a 9600 Baudios (velocidad de fabrica)
    dht.begin(); //Iniciamos la comunicación con el DHT-11
    
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH); // Enciende el LED 13 (Está integrado al Arduino. Comunmente se identifica
                          // con una "L") durante 4s antes de configurar el Bluetooth
    delay(4000);
    
    digitalWrite(13,LOW); // Apaga el LED 13 para iniciar la programacion
    
    blue.print("AT");  // Inicializa comando AT
    delay(1000);
 
    blue.print("AT+NAME"); // Configura el nuevo nombre 
    blue.print(NOMBRE);
    delay(1000);                  // espera 1 segundo
 
    blue.print("AT+BAUD");  // Configura la nueva velocidad 
    blue.print(BPS); 
    delay(1000);
 
    blue.print("AT+PIN");   // Configura el nuevo PIN
    blue.print(PASS); 
    delay(1000);    
}
 
void loop()
{
    float humedad = dht.readHumidity();       //Se lee la humedad
    float temperatura = dht.readTemperature();    //Se lee la temperatura en Celsius

    //Bluetooth
    Kotlin=blue.read(); //Igualamos la lectura del serial en la variable Kotlin

    //Envío de datos
    blue.write(temperatura); //Enviamos el dato de la temperatura
    delay(1000); //Esperamos 1 segundo y se repite el proceso
}
