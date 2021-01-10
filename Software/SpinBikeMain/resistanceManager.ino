#include <Wire.h>
#include <Adafruit_MotorShield.h>

#define MOTOR_RPM 100
#define MOTOR_FEATHER_ADDRESS 0x61
#define STEPS_PER_PERCENT 1
#define MOTOR_STEP_MODE DOUBLE

// Create the motor shield object with the defined I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(MOTOR_FEATHER_ADDRESS);

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #1 (M1 and M2)
Adafruit_StepperMotor *motor = AFMS.getStepper(200, 1);

int targetResistancePerc = 0;
int currentResistancePerc = 0;

void initResistanceManager() {
   AFMS.begin();  // create with the default frequency 1.6KHz
   motor->setSpeed(MOTOR_RPM);
}

void resistanceManagerRun() {
  uint8_t direction;
  if (targetResistancePerc != currentResistancePerc) {
    if (targetResistancePerc > currentResistancePerc) {
      direction = FORWARD;
      currentResistancePerc += STEPS_PER_PERCENT;
    }
    else {
      direction = BACKWARD;
      currentResistancePerc -= STEPS_PER_PERCENT;
    }
    motor->step(STEPS_PER_PERCENT, direction, MOTOR_STEP_MODE);
  }
  else {
    motor->release();
  }
}

void setTargetResistance(int target) {
  targetResistancePerc = target;
}

int getCurrentResistance() {
  return currentResistancePerc;
}
