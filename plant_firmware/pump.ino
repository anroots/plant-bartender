
void serveSomeWater() {

  if (isWaterReservoirEmpty()) {
    raiseNoWaterLeftAlert();
    return;
  }

  if (!isWateringPermitted()) {
    Serial.println("I am not allowed to water right now");
    return;
  }

  activatePump(2000);

  Serial.println("Serving some water...");

}

void activatePump(unsigned int duration) {

}
