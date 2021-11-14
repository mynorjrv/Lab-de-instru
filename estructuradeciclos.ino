//botones
const int onoffbutton = 12;
const int configbutton = 13;

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
const int onled = 2;
const int confled = 3;

//Constantes necesarias
float setPoint, kp, ki, kd;


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
    delay(1000);



    while(estadoconfig==true){
      config();
    }

    Serial.println("Saliendo de configuracion");
  }

  //Acá debería ir la acción :)
  Serial.println("Aca deberia pasar la accion");
  Serial.println("Por ahora imprimire valores :)");
  Serial.println(setPoint);
  Serial.println(kp);
  Serial.println(ki);
  Serial.println(kd);

  delay(1000);
  
}

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



float floatmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}