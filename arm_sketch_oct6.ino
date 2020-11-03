#include <Stepper.h>
#define STEPS 2048 // the number of steps in one revolution of your motor (28BYJ-48)
Stepper stepper(STEPS,  2, 4, 3, 5);
Stepper stepper1(STEPS, 6, 8, 7, 9);
Stepper stepper2(STEPS, 10, 12, 11, 13);
int previousPot = 0;
int joystickX = 0; 
int joystickY = 0;

void setup() {
  Serial.begin(19200); 
 }
 void loop() {
  int potValue = analogRead(A0); //loeb potentsiomeetri asendit
  joystickX = analogRead(A1); //loeb joysticki asendit 1
  joystickY = analogRead(A2); // loeb joysticki asendit 2

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" JoystickX: ");
  Serial.print(joystickX);
  Serial.print(" JoystickY: ");
  Serial.println(joystickY);
  
  stepper.setSpeed(10);
  stepper1.setSpeed(10);
  stepper2.setSpeed(10);

  stepper.step(potValue - previousPot);
  previousPot = potValue;

  if (joystickX > 600){ 
    stepper1.step(10);
  }
  if (joystickX < 400){
    stepper1.step(-10);
  }

  if (joystickY < 400){
    stepper2.step(-10);
    delay(5);
  }
  if (joystickY > 600){
    stepper2.step(10);
  }
 }
