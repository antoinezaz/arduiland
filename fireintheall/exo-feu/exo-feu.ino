const int LED_RIGHT_R = 10;
const int LED_RIGHT_O = 11;
const int LED_RIGHT_V = 12;

const int LED_LEFT_R = 7;
const int LED_LEFT_O = 6;
const int LED_LEFT_V = 5;

int timeRed;
int timeGreen;
int timeOrange;

int timeloul = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);// initialisation de la communication
    pinMode(LED_RIGHT_R,OUTPUT);
    pinMode(LED_RIGHT_O, OUTPUT);
    pinMode(LED_RIGHT_V, OUTPUT);
    
    pinMode(LED_LEFT_R,OUTPUT);
    pinMode(LED_LEFT_O, OUTPUT);
    pinMode(LED_LEFT_V, OUTPUT);

    timeGreen = 5000;    
    timeRed = 10000;
    timeOrange = 2000;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_LEFT_V,HIGH);
  digitalWrite(LED_RIGHT_R,HIGH);
  delay(timeGreen);
  digitalWrite(LED_LEFT_V,LOW);
  digitalWrite(LED_LEFT_O,HIGH);
  delay(timeOrange);
  digitalWrite(LED_O,LOW);
  digitalWrite(LED_R,HIGH);
  delay(timeRed);
  digitalWrite(LED_R,LOW);
  timeloul++;
  
  if (timeloul == 5)
  {
    for (int i = 0; i < 50; i++)
    {
      digitalWrite(LED_V,HIGH);
      delay(200);
      digitalWrite(LED_V,LOW);
      digitalWrite(LED_O,HIGH);
      delay(200);
      digitalWrite(LED_O,LOW);
      digitalWrite(LED_R,HIGH);
      delay(200);
      digitalWrite(LED_R,LOW);
    }

    timeloul = 0;
  }
}
