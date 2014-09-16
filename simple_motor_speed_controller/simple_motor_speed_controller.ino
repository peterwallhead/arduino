int potPin = A0;
int motorPin = 9;
int potValue = 0;
int motorValue = 0;
int motorCutoff = 228;

void setup() {
 Serial.begin(38400);
}
void loop() {
 potValue = analogRead(potPin);  
 motorValue = map(potValue, 0, 1023, 0, 255);
 if(motorValue > motorCutoff) {
   analogWrite(motorPin, motorValue);
 } else {
   digitalWrite(motorPin, LOW);
 } 
 Serial.print("potentiometer = " );     
 Serial.print(potValue);
 Serial.print("\t motor = ");
 Serial.println(motorValue);
 delay(2);    
}
