
boolean isWaterReservoirEmpty() {

  return measuredReservoirReading <= noWaterThreshold;
}

boolean isSoilTooDry() {

  return measuredSoilHumidity <= soilDrynessThreshold;
}


boolean isWateringPermitted() {
  unsigned int timeSinceLastRun = (int)abs(millis() - pumpLastActive);
  
  return timeSinceLastRun >= minMinutesBetweenPumps*60000;
}
