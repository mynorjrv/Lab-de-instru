#include <Servo.h>

//Distance sensor, pins and variables
#define triggerPin 11
#define echoPin 12
long t, d;

//Servo pin, object declaration and variable
#define servoPin 9
//int angulo = 55;
Servo actuador;

//botones
const int onoffbutton = 2;
const int configbutton = 3;

bool estado = false;
bool estadoconfig = false;

//Dip switch, botones de seleccion
const int setpoinButton = 7;
const int kpbutton = 8;
const int kibutton = 9;
const int kdbutton = 10;

//Poteciometros de eleccion
const int setpointPot = A4;
const int ksPot = A5;

int potvalue;

//leds para ver las cosas
//const int onled = 2;
//const int confled = 3;


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
double entrada = 0, salida, setPoint=5; 

double proporcional, integral, derivativo;

//Para ayudar con los ajustes de angulos
double mapeo1;
double mapeo2;

int angulo;


void setup(){

  Serial.begin(9600);

  pinMode(onoffbutton, INPUT);
  pinMode(configbutton, INPUT);

  pinMode(setpoinButton, INPUT);
  pinMode(kpbutton, INPUT);
  pinMode(kibutton, INPUT);
  pinMode(kdbutton, INPUT);

  pinMode(setpointPot, INPUT);
  pinMode(ksPot, INPUT);

}

void loop(){
  //condicion de encendido
  if(digitalRead(onoffbutton)==1 && estado == false){
    estado = true;
    delay(250); 

    Serial.println("Encendido");
    Serial.println("Valores iniciales:")
    Serial.print("kp: ");
    Serial.println(kp);
    Serial.print("ki: ");
    Serial.println(Ki);
    Serial.print("kd: ");
    Serial.println(kd);
    Serial.print("Set point: ");
    Serial.println(setPoint);
    Serial.print("Angulo inicial: ");
    Serial.println(actuador.read());

    //imprimir valores iniciales

    //loop dentro del loop
    while(estado == true){
      //funcion de accion cuando encendido
      encendido();
    }

    Serial.println("Apagado");
    delay(500);
  } 
  
}




//funcion de accion cuando encendido
void encendido(){

  if(digitalRead(onoffbutton)==1 && estado == true){
    estado = false;
    delay(100);
  }
  
  if(digitalRead(configbutton)==1 && estadoconfig == false){
    estadoconfig = true;

    Serial.println("Configuracion");
    //Delay para evitar rebotes
    delay(1000);

    while(estadoconfig==true){
      config();
    }

    Serial.println("Saliendo de configuracion");
    Serial.print("kp: ");
    Serial.println(kp);
    Serial.print("ki: ");
    Serial.println(Ki);
    Serial.print("kd: ");
    Serial.println(kd);
    Serial.print("Set point: ");
    Serial.println(setPoint);
    Serial.print("Angulo inicial: ");
    Serial.println(actuador.read());


  }

  //Acá debería ir la acción :)
  //Si no se apaga y no entra a configuracion pasa a la accion
  action();
  delay(100);
  
}


//Funcion de accion para configuracion
void config(){
  if(digitalRead(configbutton)==1 && estado == true){
    estadoconfig = false;
    delay(100);
  }

  while( digitalRead(setpoinButton) == HIGH ){
    delay(50);
    potvalue = analogRead(setpointPot);
    delay(50);
    setPoint = floatmap(potvalue, 0, 1023, 1, 10);
  
    Serial.print("Setpoint: ");
    Serial.println(setPoint);
    delay(100);
  }

  while( digitalRead(kpbutton) == HIGH ){
    delay(50);
    potvalue = analogRead(ksPot);
    delay(50);
    kp = floatmap(potvalue, 0, 1023, 0, 5);
  
    Serial.print("Kp: ");
    Serial.println(kp);
    delay(100);
  }

  while( digitalRead(kibutton) == HIGH ){
    delay(50);
    potvalue = analogRead(ksPot);
    delay(50);
    ki = floatmap(potvalue, 0, 1023, 0.2, 10);
  
    Serial.print("Ki: ");
    Serial.println(ki);
    delay(100);
  }

  while( digitalRead(kdbutton) == HIGH ){
    delay(50);
    potvalue = analogRead(ksPot);
    delay(50);
    kd = floatmap(potvalue, 0, 1023, 0, 10);
  
    Serial.print("Kd: ");
    Serial.println(kd);
    delay(100);
  }

}


//Funcion auxiliar de mapeo
float floatmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


//Funciones de operacion
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


//Accion
void action(){
  angulo = actuador.read();
  //Serial.println(angulo);

  
  entrada = distancia();
  delay(100);
  Serial.print("Distancia: ");
  
  salida = CPID(entrada, setPoint);
  Serial.println(entrada);
  
  delay(50);
  Serial.print("Salida: ");
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
