
const byte moistureLevelPin = A0;
const byte waterLevelSensorPin = A1;

const byte sensorPowerPin = 8;

const unsigned int soilDrynessThreshold = 100;
const unsigned int noWaterThreshold = 300;


unsigned int measuredSoilHumidity;
unsigned int measuredReservoirReading;

void setup() {
  Serial.begin(9600);

  pinMode(sensorPowerPin, OUTPUT);

  digitalWrite(sensorPowerPin, LOW);
}








void loop() {

  takeMeasurments();

  Serial.println(getCsvLine());
  if (isSoilTooDry()) {
    //serveSomeWater();
  }

  delay(1500);

}



