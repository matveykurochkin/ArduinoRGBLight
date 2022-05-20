#define RED 11
#define GREEN 12
#define BLUE 13
#define TURN_ON_COMMAND 1

byte COMMAND, REDp, GREENp, BLUEp;

void setup() {
  Serial.begin(9600);
  pinMode(COMMAND, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    COMMAND = Serial.read();
    REDp = Serial.read();
    GREENp = Serial.read();
    BLUEp = Serial.read();
  }

  if (COMMAND == TURN_ON_COMMAND ) {
    analogWrite(RED, REDp);
    analogWrite(GREEN, GREENp);
    analogWrite(BLUE, BLUEp);

  } else
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
  delay(10);
}
