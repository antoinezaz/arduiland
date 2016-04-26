void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long ms = millis(); // get the milisecond since the program is launched
  Serial.println(ms); // print ms on serial console
  delay(1000);
}
