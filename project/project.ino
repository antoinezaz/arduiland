// NOTE FOR SENSOR:
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

#include <DHT.h>
#include <Wire.h>

#define DHTPIN 6
#define DHTTYPE DHT11
#define SLAVE_ADDRESS 0x55

DHT dht(DHTPIN, DHTTYPE);
const int LED_TEMP = 12;
int dataReceived = 0;
float humidity;
float temperature;
//float farenheit;

void setup() {
  Serial.begin(9600);
  Serial.println("Start program...\n");
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode (LED_TEMP, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);

  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  //farenheit = dht.readTemperature(false); // Fareinheit

  if (isnan(humidity) || isnan(temperature)) { // || isnan(farenheit)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // float hif = dht.computeHeatIndex(farenheit, humidity);
  // float hic = dht.computeHeatIndex(temperature, humidity, false);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C ");
  /*Serial.print(farenheit);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");*/

  Serial.println("");
  isHot(t);
}

void receiveData(int byteCount) {
    while(Wire.available()) {
        dataReceived = Wire.read();
        Serial.print("Donnee recue : ");
        Serial.println(dataReceived);
    }
}

void sendData() {
    float dataResponse;
    switch (dataReceived) {
      case 0:
        break;
      case 1:
        dataResponse = temperature;
        break;
      case 2:
        dataResponse = humidity;
        break;
    }
    Wire.write((byte) dataResponse);
}

void isHot(float temp) {
  if (temp >= 22.0)
    digitalWrite(LED_TEMP, HIGH);
  else
    digitalWrite(LED_TEMP, LOW);
}

