int SER_PIN = 11; // pin 14 sur le 74HC595
int RCLK_PIN = 12; // pin 12 sur le 74HC595
int SRCLK_PIN = 8; // pin 11 sur le 74HC595

#define number_of_74hc595s 1
#define numbOfRegisterPins number_of_74hc595s * 8
boolean registers[numbOfRegisterPins];

void setup() {
  pinMode(SER_PIN, OUTPUT);
  pinMode(RCLK_PIN, OUTPUT);
  pinMode(SRCLK_PIN, OUTPUT);
  // Reset tous les pins du 74HC595
  clearRegisters();
  writeRegisters();
}

// Place tous les pins du 74HC595 à l'état "OFF"
void clearRegisters() {
  for (int i = numbOfRegisterPins - 1; i >= 0; i--) {
    registers[i] = LOW;
  }
}

// Enregistrer et afficher les valeurs dans le registre
// Exécuter uniquement APRES que toutes les valeurs aient été programmées
void writeRegisters() {
  digitalWrite(RCLK_PIN, LOW);
  for (int i = numbOfRegisterPins - 1; i >= 0; i--) {
    digitalWrite(SRCLK_PIN, LOW);
    int val = registers[i];
    digitalWrite(SER_PIN, val);
    digitalWrite(SRCLK_PIN, HIGH);
  }
  digitalWrite(RCLK_PIN, HIGH);
}

// Place un pin du 74HC595 à l'état HAUT et BAS 
void setRegisterPin(int index, int value) {
  registers[index] = value;
}

void writeCounter() {
  setRegisterPin(0, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(1, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(2, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(3, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(4, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(5, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(6, HIGH);
  writeRegisters();
  delay(5000);
  setRegisterPin(7, HIGH);
  writeRegisters();
  delay(5000);
}

void loop() {
  setRegisterPin(0, LOW);
  setRegisterPin(1, LOW);
  setRegisterPin(2, LOW);
  setRegisterPin(3, LOW);
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, LOW);
  setRegisterPin(7, LOW);
  writeRegisters(); // Doit être exécuté pour appliquer les changements
  // Executer seulement une fois que toutes les valeurs ont été enregistrées comme vous le souhaitiez

  writeCounter();
}
