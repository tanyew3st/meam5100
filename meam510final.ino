#include "vive510.h"
#include "ultrasonic510.h"

#define VIVESIGNAL 1 // GPIO pin receiving signal from Vive circuit
#define TRIG_PIN 4 // GPIO pin for Ultrasonic sensor trigger
#define ECHO_PIN 5 // GPIO pin for Ultrasonic sensor echo

Vive510 vive1(VIVESIGNAL);
UltrasonicSensor510 ultrasonic1(TRIG_PIN, ECHO_PIN);

void setup(){
  Serial.begin(9600);
  Serial.println("Vive and Ultrasonic sensors started");
  vive1.begin();
}

void loop() {
  if (vive1.status() == VIVE_RECEIVING) {
    Serial.printf("Vive X: %d, Y: %d\n",vive1.xCoord(), vive1.yCoord());
  } else {
    vive1.sync(15); // try to resync 15 times (nonblocking);
  }

  float distance = ultrasonic1.getDistance();
  Serial.print("Ultrasonic Distance: ");

  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}
