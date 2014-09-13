
boolean isWaterReservoirEmpty() {

  return measuredReservoirReading <= noWaterThreshold;
}

boolean isSoilTooDry() {

  return measuredSoilHumidity <= soilDrynessThreshold;
}


boolean isWateringPermitted() {

  return true;

}
