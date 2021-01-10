#ifndef _WORKOUTTYPES_H
#define _WORKOUTTYPES_H

enum workoutType {
   interval,
   calibration
};

enum intervalWorkoutState {
    warmup,
    highIntensity,
    lowIntensity,
    cooldown
};

typedef struct workoutCell {
    unsigned int duration;
    unsigned int targetResistance;
    char *logEntry;
} workoutCell;

#endif // _WORKOUTTYPES_H