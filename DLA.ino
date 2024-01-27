#include <Servo.h>

Servo doorLockServo;  // Create a servo object to control the door lock

const int openButtonPin = 5;   // Button to open the door
const int closeButtonPin = 3;  // Button to close the door

int angleClosed = 0;   // Angle to close the door lock
int angleOpen = 90;    // Angle to open the door lock

void setup() {
  doorLockServo.attach(9);  // Attach the servo to pin 9
  pinMode(openButtonPin, INPUT_PULLUP);  // Set open button pin as input with pull-up resistor
  pinMode(closeButtonPin, INPUT_PULLUP); // Set close button pin as input with pull-up resistor
}

void loop() {
  // Check if the open button is pressed
  if (digitalRead(openButtonPin) == LOW) {
    openDoor();
  }

  // Check if the close button is pressed
  if (digitalRead(closeButtonPin) == LOW) {
    closeDoor();
  }
}

void openDoor() {
  doorLockServo.write(angleOpen);  // Move the servo to the open position
  delay(1000);  // Wait for the servo to reach the open position
}

void closeDoor() {
  doorLockServo.write(angleClosed);  // Move the servo to the closed position
  delay(1000);  // Wait for the servo to reach the closed position
}
