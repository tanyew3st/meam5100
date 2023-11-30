#include "ultrasonic510.h"

UltrasonicSensor510::UltrasonicSensor510(int trigPin, int echoPin)
{
    m_trigPin = trigPin;
    m_echoPin = echoPin;
    pinMode(m_trigPin, OUTPUT);
    pinMode(m_echoPin, INPUT);
}

long UltrasonicSensor510::readDuration()
{
    digitalWrite(m_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(m_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trigPin, LOW);
    return pulseIn(m_echoPin, HIGH);
}

float UltrasonicSensor510::getDistance()
{
    long duration = readDuration();
    return duration / 29.0 / 2.0;
}
