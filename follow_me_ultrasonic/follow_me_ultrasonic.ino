/*
  Parallax Ping))) ultrasonic sensor code from tronixstuff.wordpress.com - CC by-sa-nc
  http://littlebirdelectronics.com.au/blogs/news/4724922-tutorial-parallax-ping-ultrasonic-sensor
  Connect Ping))) signal pin to Arduino digital 8

  Motor shield control functions added by Peter Wallhead.

  This example code is in the public domain.

*/

int signal=8;
int distance;
unsigned long pulseduration=0;

// Assign motor shield pins that start and stop the motor.
int PWM1 = 5;
int PWM2 = 6;

// Assign motor shield pins that dictate motor direction.
int DIR1 = 4;
int DIR2 = 7;

// Set default motor speed.
int SPEED = 130;

void setup()
{
  pinMode(signal, OUTPUT);
  Serial.begin(9600);
  
  // Set pin modes to output for all those used by the motor shield.
  int i;
  for(i=4; i<=7; i++) {
      pinMode(i, OUTPUT);
  }
  
  pause(2000);
  
}

void measureDistance()
{
  // Set pin as output so we can send a pulse.
  pinMode(signal, OUTPUT);

  // Set output to LOW.
  digitalWrite(signal, LOW);
  delayMicroseconds(5);
  
  // Now send the 5uS pulse out to activate Ping)))
  digitalWrite(signal, HIGH);
  delayMicroseconds(5);
  digitalWrite(signal, LOW);
  
  // Now we need to change the digital pin 
  // to input to read the incoming pulse.
  pinMode(signal, INPUT);
  
  // Finally, measure the length of the incoming pulse.
  pulseduration=pulseIn(signal, HIGH);
  
  // Divide the pulse length by half.
  pulseduration=pulseduration/2;
  
  // Now convert to centimetres. We're metric here people...
  distance = int(pulseduration/29);
}

void loop()
{
  // Get the raw measurement data from Ping)))
  measureDistance();
    
  if(distance < 30) {
    
    while(distance == 15) {
      pause(100);
      measureDistance();
    }

    while(distance < 15) {
      reverse(100);
      measureDistance();
    }
    
    forward(100);
  }
  
  delay(25);
   
}

void forward(int ti) {
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);
  
  int i;
  for(i=0; i<=ti; i++) {
    analogWrite(PWM1,200);
    analogWrite(PWM2, 200);
    delay(1);
  }
  
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
}

void reverse(int ti) {
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, LOW);
  
  int i;
  for(i=0; i<=ti; i++) {
    analogWrite(PWM1,200);
    analogWrite(PWM2, 200);
    delay(1);
  }
  
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
}

void left(int ti) {
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, HIGH);
  
  int i;
  for(i=0; i<=ti; i++) {
    analogWrite(PWM1,200);
    analogWrite(PWM2, 200);
    delay(1);
  }
  
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
}

void right(int ti) {
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);
  
  int i;
  for(i=0; i<=ti; i++) {
    analogWrite(PWM1,200);
    analogWrite(PWM2, 200);
    delay(1);
  }
  
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
}

void pause(int ti) {
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  delay(ti);
}

