/*
  The circuit:
  * Potentiometer attached to analog input 0
  * center pin of the potentiometer to the analog pin
  * one side pin (either one) to ground
  * the other side pin to +5V
  * Motor attached to motor 1 connector on shield

  Created by Peter Wallhead
 
  This example code is in the public domain.
 
*/

//Assign motor shield pins that start and stop the motor.
int PWM1 = 5;
int PWM2 = 6;

//Assign motor shield pins that dictate motor direction.
int DIR1 = 4;
int DIR2 = 7;

//Set motor rotation speed (max: 255)
int rotationSpeed = 255;

int potPin = A0;            // select the input pin for the potentiometer

void setup() { 
}

void loop() {
    SlideToValue(0);
    SlideToValue(1023);
    SlideToValue(512);
}

void SlideToValue(int targetValue){
  int val = analogRead(potPin);
  while(abs(val - targetValue) > 1){
      val = analogRead(potPin);
      if(val > targetValue){
          digitalWrite(DIR1, LOW);
          digitalWrite(DIR2, HIGH);
      }else{
          digitalWrite(DIR1, HIGH);
          digitalWrite(DIR2, LOW);
      }
      //analogWrite(PWM1, max(min(abs(val - targetValue), 255), 255));
      analogWrite(PWM1, 255);
  }
      // Turn off motor
      digitalWrite(DIR1, LOW);
      digitalWrite(DIR2, LOW);  
      analogWrite(PWM1, 0);
      delay(100);
}
