
int Vo; 
float R1 = 1000;       // resistencia fija  
float logR2, R2, TEMP;
float c1 = 2.229674985e-03, c2 = 1.211871452e-04, c3 = 8.713435086e-07; //de la pagina web


void setup() {
Serial.begin(9600);   // inicializa comunicacion serie a 9600 bps
}

void loop() {
  Vo = analogRead(A0);      // lectura de A0
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //  tension a resistencia
  logR2 = log(R2);     
  TEMP = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));   // ecuacion S-H
  TEMP = TEMP - 273.15-8;   // Kelvin a Centigrados (Celsius) con correcion de 8 grados para temperatura ambiente

  Serial.print("Temperatura: ");  // imprime valor en monitor serie
  Serial.print(TEMP);
  Serial.println(" C"); 
  delay(1200);       // demora de medio segundo entre lecturas
}
