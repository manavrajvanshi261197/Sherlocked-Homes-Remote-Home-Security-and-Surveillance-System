
#include <Servo.h>

Servo door;  

int pos = 0; 
int pir_pin =8;
int trig = 2;
int echo = 3;
int ldr_pin = A0;
int prox_pin = A1;

void setup() {
  Serial.begin(9600);
  door.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(10,OUTPUT);
  pinMode(1,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(13,OUTPUT);
 
}

String temp;
boolean prox,ultrasonic,ldr,pir;


void loop() {
  
  prox = read_prox();
  ultrasonic = read_ultrasonic();
  ldr  = read_ldr();
  pir = read_pir();
 /*
  Serial.print(prox);
  Serial.print("\t");
  Serial.print(ultrasonic);
  Serial.print("\t");
  Serial.print(ldr);
  Serial.print("\t");
  Serial.println(pir);
  */
  while (Serial.available() > 0) {
                // read the incoming byte:
                char c = Serial.read();
                temp += c;
                
              }
            
                
  if(temp == "open"){
         door_open();
      }
  else if(temp == "close"){
          door_close();
      }
  //Serial.println(temp);                         
  temp = "";            
      
  if( prox | ldr | ultrasonic|  pir ){
   digitalWrite(10,HIGH);
   digitalWrite(13,HIGH);
   Serial.println("MOTION");
  }      
  
  
  else{
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    Serial.println("NO MOTION");
  }
  
        
  delay(500);
  }


void door_open(){
  for (pos = 95; pos>=5; pos--){
    door.write(pos);
    delay(5);
  }
}

void door_close(){
  for (pos = 5; pos<=95; pos++){
    door.write(pos);
    delay(5);
  }
}

boolean read_ldr(){
int ldr = analogRead(ldr_pin);
if(ldr >= 300){
  return true;
 }
else{
  return false;
 }
}

boolean read_ultrasonic(){
 
 int duration, distance;
 digitalWrite(trig,LOW);
 digitalWrite(trig,HIGH);
 delay(2);
 digitalWrite(trig,LOW);

 duration = pulseIn(echo,HIGH);
 distance = (duration/2) / 29.1;
 
 if(distance <= 3){
  return true;
 }
else{
  return false;
 }
 
}


boolean read_pir(){
  int motion = digitalRead(pir_pin);
  if(motion == 1){
  return true;
 }
else{
  return false;
 }
 
}



boolean read_prox(){
  int dist = analogRead(prox_pin);
  if(dist >=300){
  return true;
}
else{
  return false;
}
}

