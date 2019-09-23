
#include <Servo.h>

Servo door;  

int pos = 0;   

void setup() {
  door.attach(9);  // attaches the servo on pin 9 to the servo object
}



void loop() {
  door_open();
  delay(200);
  door_close();
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

