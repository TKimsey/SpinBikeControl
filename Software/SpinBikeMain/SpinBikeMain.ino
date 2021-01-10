#include "workoutTypes.h"

workoutType selectedWorkout = interval;
void setup() {
  initWorkout(selectedWorkout);
}

void loop() {
  runWorkout();
}
