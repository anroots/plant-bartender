
void raiseNoWaterLeftAlert() {
  analogWrite(buzzerPin, 150);
  delay(500);
  digitalWrite(buzzerPin, LOW);
}

void notifyPumpStart() {
  analogWrite(buzzerPin, 254);
  delay(500);
  digitalWrite(buzzerPin, LOW);
}
