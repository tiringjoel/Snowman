#ifndef Snowman_h
#define Snowman_h

#include "Arduino.h"
#include "Servo.h"

enum Direction
{
  Direction_POSITIVE,
  Direction_NEGATIVE
};

class Snowman
{
  public:
    Snowman(int pin, int lowerAngle, int upperAngle, int velocity);
    void begin();
    void loop();
  private:
    bool isItTimeToUpdate();
    void updateSetPoint();

    Servo _servo;
    int _pin;
    int _upperAngle;
    int _lowerAngle;
    int _currentSetPoint;
    enum Direction _currentDirection;
    unsigned long _setPointRate;
    unsigned long _lastSetPointUpdateTime;
};

#endif