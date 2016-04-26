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
boolean switchColor = true;

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
    timeOrange = 2000;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(switchColor){
    digitalWrite(LED_LEFT_V,HIGH);
    digitalWrite(LED_RIGHT_R,HIGH);
    delay(timeGreen);
    digitalWrite(LED_LEFT_V,LOW);
    digitalWrite(LED_LEFT_O,HIGH);
    delay(timeOrange);
    digitalWrite(LED_RIGHT_R,LOW);
    digitalWrite(LED_LEFT_O,LOW);
  } else {
    digitalWrite(LED_RIGHT_V,HIGH);
    digitalWrite(LED_LEFT_R,HIGH);
    delay(timeGreen);
    digitalWrite(LED_RIGHT_V,LOW);
    digitalWrite(LED_RIGHT_O,HIGH);
    delay(timeOrange);
    digitalWrite(LED_LEFT_R,LOW);
    digitalWrite(LED_RIGHT_O,LOW);
  }
  
  timeloul++;
  switchColor = !switchColor;


  
  
  if (timeloul == 2)
  {
    for (int i = 0; i < 50; i++)
    {
      digitalWrite(LED_LEFT_V,HIGH);
      delay(200);
      digitalWrite(LED_LEFT_V,LOW);
      digitalWrite(LED_LEFT_O,HIGH);
      delay(200);
      digitalWrite(LED_LEFT_O,LOW);
      digitalWrite(LED_LEFT_R,HIGH);
      delay(200);
      digitalWrite(LED_LEFT_R,LOW);
      delay(200);

      
      digitalWrite(LED_RIGHT_V,HIGH);
      delay(200);
      digitalWrite(LED_RIGHT_V,LOW);
      digitalWrite(LED_RIGHT_O,HIGH);
      delay(200);
      digitalWrite(LED_RIGHT_O,LOW);
      digitalWrite(LED_RIGHT_R,HIGH);
      delay(200);
      digitalWrite(LED_RIGHT_R,LOW);
    }

    timeloul = 0;
  }
}
