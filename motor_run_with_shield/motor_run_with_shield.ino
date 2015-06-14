//Assign motor shield pins that start and stop the motor.
int PWM1 = 5;
int PWM2 = 6;

//Assign motor shield pins that dictate motor direction.
int DIR1 = 4;
int DIR2 = 7;

//Set motor speed.
int SPEED = 255;


void setup() {
  // Set pin modes to output for all those used by the motor shield.
  int i;
  for(i=4; i<=7; i++) {
      pinMode(i, OUTPUT);
  }
  
  //Set both motors to run forwards.
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);

}


void loop() {
  //Start both motors at set SPEED 
  analogWrite(PWM1, SPEED);
  analogWrite(PWM2, SPEED);
}

