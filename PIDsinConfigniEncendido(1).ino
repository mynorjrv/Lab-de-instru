//12 de noviembre
#include <Servo.h>

//Distance sensor, pins and variables
#define triggerPin 6
#define echoPin 5
long t, d;

//Servo pin, object declaration and variable
#define servoPin 3
//int angulo = 55;
Servo actuador;

// PID
//Debido a que la amplitud de voltaje maxima es de 5
//lo dejamos en 4.1
double kp = 4.1;
//ki mas pequeña
//tenemos ki = 1.7
double ki = 1.7;
//pdi
//para kd > 3.7 oscila demasiado
//el rango adecuado para evitar mayor inestabilidad 
//es entre 2.9 y 3.3>]: es muy preciso
//para kd = 2 tambien es muy estable
//en 2.5 se ve muy bien
double kd = 2.6;
unsigned long tiempoActual = 0, tiempoAnterior = 0;
double diferenciaTiempo, error = 0, errorAnterior = 0;
double entrada = 0, salida, setPoint; 

double proporcional, integral, derivativo;

double mapeo1;
double mapeo2;

void setup()
{
  Serial.begin(9600);

  actuador.attach(9);
  //angulo inicial
  actuador.write(55);
  
  //Sensor de distancia
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);

}

void loop(){
  int angulo = actuador.read();
  //Serial.println(angulo);

  
  entrada = distancia();
  delay(100);
  Serial.print("Distancia: ");
  
  salida = CPID(entrada, 5);
  Serial.println(entrada);
  
  delay(50);
  Serial.print("Salida0: ");
  Serial.println(salida);

  //modificacion
  
  
  //funciona de 12 a 98 grados
  if(entrada <= 12 && salida < 0){
    mapeo1 = map(abs(salida), 0, 25, 12, 80);
    if (angulo + mapeo1 <= 98){
      salida = angulo + mapeo1;
      }else{
        salida = angulo;
      }
      
  }else if (salida > 0 && salida <= 20){
    mapeo2 = map(abs(salida), 0, 15, 11, 30);
    if (angulo - mapeo2 > 12){
      salida = angulo - mapeo2;
    }else{
      salida = angulo;    
    }
  }else{
    
    
    salida = angulo;
  }
  //Serial.print("Salida: ");
  //Serial.println(salida);
  //modificacion termina

  actuador.write(salida);
  
  delay(150);

  
  
}

double CPID(double retroalimentacion, double spoint){
  tiempoActual = millis();
  diferenciaTiempo = tiempoActual-tiempoAnterior;

  error = spoint - retroalimentacion;

  proporcional = kp * error;
  derivativo = kd * ((error-errorAnterior)/diferenciaTiempo);
  //Por que -4 y 4?
  if (error > -1 && error < 1){
    integral = integral + (ki*error);
  }else{
    integral = 0;
  }

  double resultado = proporcional + derivativo + integral;
  errorAnterior = error;
  tiempoAnterior = tiempoActual;
  return resultado;
}

long distancia(){
  digitalWrite(triggerPin, HIGH);
  delay(15);
  digitalWrite(triggerPin, LOW);
  t = pulseIn(echoPin, HIGH);
  //d = t/59; //No se el motivo de dividir entre 59
  //yo tampoco, lo vi en un video
  d = t/59; //distancia en cm
  
  return d;
}
