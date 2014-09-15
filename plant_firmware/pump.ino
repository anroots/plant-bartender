
void serveSomeWater() {

  if (isWaterReservoirEmpty()) {
    raiseNoWaterLeftAlert();
    return;
  }

  if (!isWateringPermitted()) {
    return;
  }
  
  notifyPumpStart();
  activatePump(getPumpDuration());
}

unsigned int getPumpDuration() {

  unsigned int moistureBonus = (500-measuredSoilHumidity)*5;
  
  return defaultPumpDuration + moistureBonus;
}

void activatePump(unsigned int duration) {
  digitalWrite(pumpPowerPin, HIGH);
  delay(duration);
  digitalWrite(pumpPowerPin, LOW);
  pumpLastActive = millis();
}
