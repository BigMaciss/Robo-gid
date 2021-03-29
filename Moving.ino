#include <GyverStepper.h>

GStepper< STEPPER2WIRE> stepperL(1024, 2, 4, 7);
GStepper< STEPPER2WIRE> stepperR(1024, 8, 12, 13);

int command = 0;
int distanse = 0;

void  movingForward(int distanse) {
  stepperL.setTarget(-distanse, RELATIVE);
  stepperR.setTarget(distanse, RELATIVE);
}
void  movingBack(int distanse) {
  stepperL.setTarget(distanse, RELATIVE);
  stepperR.setTarget(-distanse, RELATIVE);
}
void  rotateRight(int distanse) {
  stepperL.setTarget(-distanse, RELATIVE);
  stepperR.setTarget(-distanse, RELATIVE);
}
void  rotateLeft(int distanse) {
  stepperL.setTarget(distanse, RELATIVE);
  stepperR.setTarget(distanse, RELATIVE);
}

void setup() {
  Serial.begin(115200);
  stepperL.setRunMode(FOLLOW_POS);
  stepperL.setMaxSpeed(400);
  stepperL.setAcceleration(500);

  stepperR.setRunMode(FOLLOW_POS);
  stepperR.setMaxSpeed(400);
  stepperR.setAcceleration(500);
}
void loop() {
  int read_1 = Serial.read();
  if (read_1 != -1) {
    command = read_1 - 48;
    Serial.println(command);
  }

  if (command == 8) {
    movingForward(1000);
    command = 0;
  }
  else if (command == 2) {
    movingBack(1000);
    command = 0;
  }
  else if (command == 6) {
    rotateRight(1000);
    command = 0;
  }
  else if (command == 4) {
    rotateLeft(1000);
    command = 0;
  }
}
