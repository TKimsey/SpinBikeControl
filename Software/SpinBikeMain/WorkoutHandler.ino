#include "workoutTypes.h"

#define MILLIS_TO_SECONDS 1000
workoutType workout;

unsigned long startTimeMillis;
workoutCell currWorkoutCell;

void initWorkout(workoutType selectedWorkout)
{
  Serial.begin(9600);
  workout = selectedWorkout;
  startTimeMillis = millis();
  initResistanceManager();

  switch (workout)
  {
  case interval:
    currWorkoutCell = getNextIntervalWorkoutCell();
    Serial.println(currWorkoutCell.logEntry);
    break;
  default:
    break;
  }
}

void runWorkout()
{
  int targetResistance;
  unsigned long currTimeMillis = millis();
  switch (workout)
  {
  case interval:
    if ((currTimeMillis - startTimeMillis) > (currWorkoutCell.duration * MILLIS_TO_SECONDS))
    {
      currWorkoutCell = getNextIntervalWorkoutCell();
      startTimeMillis = currTimeMillis;
      Serial.println(currWorkoutCell.logEntry);
    }
    targetResistance = currWorkoutCell.targetResistance;
    break;
  default:
    targetResistance = 0;
    break;
  }
  setTargetResistance(targetResistance);

  resistanceManagerRun();
}
