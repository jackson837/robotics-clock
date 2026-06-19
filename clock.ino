#include <Servo.h>

Servo myServo; 


int angles[] = {0, 60, 120, 180, 120, 60};
int angleIndex = 0;

unsigned long previousTime = 0;

const unsigned long interval = 600000; 

void setup() {
  myServo.attach(9);
  // Start at the first position
  myServo.write(angles[angleIndex]);
}
 
void loop() {
  unsigned long currentTime = millis(); 

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    
    angleIndex = (angleIndex + 1) % 6;
    myServo.write(angles[angleIndex]);
  }
}
