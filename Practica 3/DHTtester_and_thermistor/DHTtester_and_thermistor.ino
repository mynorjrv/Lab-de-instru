// Sketch para tomar temperatura simultameneamente del DTH y un termistor
// Basado en el ejemplo DHTtester

// Requiere las siguientes librerias de Arduino
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include <math.h>

// Pin al que se conecatrá el sensor
#define DHTPIN 5     // Debe ser un pin digital


// Define el tipo de sensor, en este caso sólo nos interesa el DHT11
// Revisar el sketch original para otro tipo de sensores
#define DHTTYPE DHT11   // DHT 11


// Instrucciones de conección del sensor:
// Conectar el pin 1 (a la izquierda) del sensor a +5V o +3.3V
// Conectar el pin 2 del sensor al DHTPIN elegido (para conectar al arduino)
// Conectar el pin 3 (a la derecha) del sensor a tierra
// (si el sensor tiene tres pines)
// Conectar el pin 4 (a la derecha) del sensor a tierra 
// y dejar el pin 3 sin conectar
// (si el sensor tiene cuatro pines)
// Conectar una resistencia de 10k del pin 2 (data) a pin 1 (power)
// del sensor.

// Inicializacion del sensor
DHT dht(DHTPIN, DHTTYPE);


 


void setup() {
  Serial.begin(9600);
  // Serial.println(F("DHTxx test!"));

  dht.begin();

  // Imprimiendo mediciones
  Serial.print(F("T_sensor"));
  Serial.print("\t");
  Serial.print(F("T_termistor"));
  Serial.print("\t");
  Serial.print(F("T_sensor_redondeado"));
  Serial.print("\t");
  Serial.println(F("T_termistor_redondeado"));
}

void loop() {
  // Tiempo de espera entre mediciones
  delay(2000);

  // Leer temperatura y humedad toma alrededor de 250 milisegundos
  // Las lecturas de sensor pueden tomar mas dependiendo del sensor

  // Lee la temperatura en celcius (por default)
  float t_sensor = dht.readTemperature();

  // Chequea si hay error de lectura con el sensor e intenta de nuevo.
  if (isnan(t_sensor)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Lee la temperatura del termistor
  float t_termistor = readResistor();



  // Imprimiendo mediciones
  Serial.print(t_sensor);
  Serial.print("\t");
  Serial.print(t_termistor);
  Serial.print("\t");
  Serial.print(round(t_sensor));
  Serial.print("\t");
  Serial.println(round(t_termistor));
}


float readResistor(){
  int Vo = analogRead(A0); 
  float R1 = 1000;       // valor de la resistencia fija  
  //Factores de la ecuacion de Steinhart-Hart, tomados de la web
  float c1 = 2.229674985e-03, c2 = 1.211871452e-04, c3 = 8.713435086e-07;

  //Modelo de Steinhart-Hart
  float R2 = R1 * (1023.0 / (float(Vo)) - 1.0); //  tension a resistencia
  float logR2 = log(R2);     
  float TEMP = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));   // ecuacion S-H

  //Kelvin a Centigrados y correccion de 8 grados para temperatura ambiente
  TEMP = TEMP - 273.15; //Conversion
  TEMP = TEMP + 7; //Ajuste

  return TEMP;
}
