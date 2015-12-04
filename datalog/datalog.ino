unsigned long deltatime;
unsigned long previousMillis;
int PIN[] = {A0,A1,A2,A3,A4,A5};
float seconds = .1;

void setup() {
  Serial.begin(9600);
  deltatime = 1000*seconds;
  previousMillis = 0;
}

void loop() {
  int IN[] = {0,0,0,0,0,0};
  if (millis() - previousMillis >= deltatime)
  {
    previousMillis = millis();
    for (int i = 0; i < 6; i++)
    {
      IN[i] = analogRead(PIN[i]*5/1023);
      Serial.print(IN[i]);
      if (i == 5)
      {
        Serial.flush();
        break;
      }
      Serial.print(",");
    }
  }
}
