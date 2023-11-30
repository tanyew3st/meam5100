#ifndef ULTRASONICSENSOR510_H
#define ULTRASONICSENSOR510_H

#include <Arduino.h>

class UltrasonicSensor510
{
private:
    int m_trigPin;
    int m_echoPin;

    long readDuration();
public:
    UltrasonicSensor510(int trigPin, int echoPin);
    float getDistance();
};

#endif
