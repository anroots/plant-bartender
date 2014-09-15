// Power-saving functions
#include <JeeLib.h> 

// Setup watchdog
ISR(WDT_vect) { Sleepy::watchdogEvent(); }

const byte moistureLevelPin = A0;
const byte waterLevelSensorPin = A1;
const byte pumpPowerPin = 7;
const byte sensorPowerPin = 8;
const byte buzzerPin = 4;

const unsigned int defaultPumpDuration = 3000;
const unsigned int soilDrynessThreshold = 30;
const unsigned int noWaterThreshold = 100;

unsigned int measuredSoilHumidity;
unsigned int measuredReservoirReading;
unsigned int pumpLastActive = 0;
unsigned int minMinutesBetweenPumps = 1;
unsigned int minutesBetweenMeasurements = 1;

void setup() {

  pinMode(sensorPowerPin, OUTPUT);
  pinMode(pumpPowerPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(sensorPowerPin, LOW);
  digitalWrite(pumpPowerPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {

  takeMeasurments();
  
  if (isSoilTooDry()) {
    serveSomeWater();
  }

  Sleepy::loseSomeTime(minutesBetweenMeasurements*60000);
}



