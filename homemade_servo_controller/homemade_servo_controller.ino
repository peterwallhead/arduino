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

int rotorPin = A0;            // select the input pin for the potentiometer
int controlPin = A1;          // select the input pin for the potentiometer
int rotorValue = 0;           // variable to store the value coming from the potentiometer
int rotationDegrees = 0;      // defaulted here, but is created by mapping rotorValue to a value between 0-270
int requiredPosition = 135;   // initial position the motor should turn to

void setup() { 
  Serial.begin(9600);
}

void loop() {
  // read the value from the potentiometer
  rotorValue = analogRead(rotorPin);   
  rotationDegrees = map(rotorValue, 0, 1023, 0, 270);   
  Serial.print(requiredPosition);
  Serial.print("\t ");
  Serial.println(rotationDegrees);
  
  if(rotationDegrees != requiredPosition) {
    if(rotationDegrees > requiredPosition) {
      digitalWrite(DIR1, LOW);
      analogWrite(PWM1, rotationSpeed);
    }
    
    if(rotationDegrees < requiredPosition) {
      digitalWrite(DIR1, HIGH);
      analogWrite(PWM1, rotationSpeed);
    }
  } else {    
    analogWrite(PWM1, 0);
     
  }
  
  // read value from pot 20 times per second
  delay(50);   
                  
}