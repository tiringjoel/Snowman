#include "Arduino.h"
#include "Snowman.h"

Snowman::Snowman(int pin, int lowerAngle, int upperAngle, int velocity)
{
    _pin = pin;
    _lowerAngle = lowerAngle;
    _upperAngle = upperAngle;
    _setPointRate = 1000 / velocity;
}

void Snowman::begin()
{
    _servo.attach(_pin);
    _currentSetPoint = _lowerAngle;
    _lastSetPointUpdateTime = millis();
}

void Snowman::loop()
{
    if (isItTimeToUpdate())
    {
        _servo.write(_currentSetPoint);
        Serial.println(_currentSetPoint);
        updateSetPoint();
    }
}

void Snowman::updateSetPoint()
{
    if (_currentSetPoint == _lowerAngle)
    {
        _currentDirection = Direction_POSITIVE;
    }

    if (_currentSetPoint == _upperAngle)
    {
        _currentDirection = Direction_NEGATIVE;
    }

    (_currentDirection == Direction_POSITIVE) ? _currentSetPoint++ : _currentSetPoint--;
}

bool Snowman::isItTimeToUpdate()
{
    unsigned long currentMillis = millis();

    if ((currentMillis - _lastSetPointUpdateTime) > _setPointRate)
    {
        _lastSetPointUpdateTime = currentMillis;
        return true;
    }

    return false;
}