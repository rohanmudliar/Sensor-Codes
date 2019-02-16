#include <Servo.h>

Servo servo;
int angle = 10;

void setup() {
  servo.attach(8);
  servo.write(angle);
}


void loop() { 
  for(angle = 10; angle < 180; angle++) {                                  
    servo.write(angle);               
    delay(10);                   
  } 

  for(angle = 180; angle > 10; angle--) {                                
    servo.write(angle);           
    delay(10);       
  } 
} 
