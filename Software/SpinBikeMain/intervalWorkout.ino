#include "workoutTypes.h"

unsigned int numCycles = 5;
unsigned int currCycle = 0;

unsigned int warmupTimeSec = 600;
unsigned int highIntensityTimeSec = 30;
unsigned int lowIntensityTimeSec = 30;
unsigned int restTimeSec = 600;

unsigned int warmupResistance = 45;
unsigned int highIntensityResistance = 85;
unsigned int lowIntensityResistance = 25;
unsigned int restResistance = 35;

workoutCell warmupCell = {warmupTimeSec, warmupResistance, "Warmup"};
workoutCell highIntensityCell = {highIntensityTimeSec, highIntensityResistance, "High Intensity"};
workoutCell lowIntensityCell = {lowIntensityTimeSec, lowIntensityResistance, "Low Intensity"};
workoutCell restCell = {restTimeSec, restResistance, "Rest"};

intervalWorkoutState workoutState;

void initIntervalWorkout() {
   workoutState = warmup;
}

workoutCell getNextIntervalWorkoutCell() {
   workoutCell res;
   switch (workoutState)
   {
   case warmup:
      res = warmupCell;
      workoutState = highIntensity;
      break;
   case highIntensity:
      res = highIntensityCell;
      workoutState = lowIntensity;
      break;
   case lowIntensity:
      res = lowIntensityCell;
      currCycle++;
      if(currCycle >= numCycles) {
         workoutState = cooldown;
      }
      else
      {
         workoutState = highIntensity;
      }
      break;
   case cooldown:
      res = restCell;
      break;
   default:
      break;
   }
   return res;
}