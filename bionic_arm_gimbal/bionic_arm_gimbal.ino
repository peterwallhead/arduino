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

  armController(0,0);
  delay(5000);

}

void loop() {
  armController(0,-4);
  delay(1000);
  armController(4,-4);
  delay(1000);
  armController(4,0);
  delay(1000);
  armController(4,4);
  delay(1000);
  armController(0,4);
  delay(1000);
  armController(-4,4);
  delay(1000);
  armController(-4,0);
  delay(1000);
  armController(-4,-4);
  delay(1000);
}

void armController(int x, int y) {
  current_x_pos = map(x, -4, 4, 30, 150);
  current_y_pos = map(y, -4, 4, 30, 150);
  Serial.print("X axis servo = ");
  Serial.println(current_x_pos);
  Serial.print("Y axis servo = ");
  Serial.println(current_y_pos);
  x_servo.write(current_x_pos);
  y_servo.write(current_y_pos);
}

