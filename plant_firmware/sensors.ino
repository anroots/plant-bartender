
unsigned int takeAnalogReading(byte sensorPin, byte delayTime = 50) {
  unsigned int reading;
  
  // Dummy reading
  reading = analogRead(sensorPin);

  // - Allow some time to the sensor to turn on
  // - Allow some time to the Atmega ADC to switch pins (when analogRead from a different pin occured)
  delay(delayTime);

  // Actual reading
  reading = analogRead(sensorPin);

  return reading;
}


void takeMeasurments() {
  powerOnSensors();
  delay(500);
  measuredSoilHumidity = getSoilHumidity();
  measuredReservoirReading = getWaterReservoirReading();

  powerOffSensors();
}

void powerOnSensors() {
  digitalWrite(sensorPowerPin, HIGH);
}

void powerOffSensors() {
    digitalWrite(sensorPowerPin, LOW);
}

unsigned int getSoilHumidity() {
  return takeAnalogReading(moistureLevelPin);
}

unsigned int getWaterReservoirReading() {
  return takeAnalogReading(waterLevelSensorPin);
}
