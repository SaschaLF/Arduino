#define PIN_SHIFT 8   // connected to SHCP
#define PIN_STORE 9   // connected to STCP
#define PIN_DATA  10  // connected to DS

byte count = 0;

void setup()
{
  pinMode(PIN_STORE, OUTPUT);
  pinMode(PIN_SHIFT, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);


  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, count);
  digitalWrite(PIN_STORE, HIGH);

  delay(2000);
}

void loop ()
{
  count = 165;
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, count);
  digitalWrite(PIN_STORE, HIGH);
  delay(2000);

  count = 90;
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, count);
  digitalWrite(PIN_STORE, HIGH);
  delay(2000);


}
