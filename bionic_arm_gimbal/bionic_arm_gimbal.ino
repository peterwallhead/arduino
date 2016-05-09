#include <Servo.h>

Servo x_servo;
Servo y_servo;

int x_cord = 0; //-3 to 3
int y_cord = 0; //-3 to 3

int current_x_pos = 0;
int current_y_pos = 0;

void setup() {

  Serial.begin(38400);
  
  x_servo.attach(9);
  y_servo.attach(10);

}

void loop() {
  armController(0,0);
  delay(2000);
  armController(-2,-2);
  delay(2000);
  armController(0,-4);
  delay(2000);
  armController(2,-2);
  delay(2000);
  armController(0,0);
  delay(2000);
  armController(-2,2);
  delay(2000);
  armController(0,4);
  delay(2000);
  armController(1,2);
  delay(2000);
}

void armController(int x, int y) {
  current_x_pos = map(x, -3, 3, 1, 179);
  current_y_pos = map(y, -3, 3, 1, 179);
  Serial.println(current_x_pos);
  Serial.println(current_y_pos);
  x_servo.write(current_x_pos);
  y_servo.write(current_y_pos);
}

