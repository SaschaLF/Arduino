#define PIN_SHIFT 4   // connected to SHCP
#define PIN_STORE 3   // connected to STCP
#define PIN_DATA  2  // connected to DS

const int ziffer1 =10;
const int ziffer2= 11;
const int ziffer3= 12;
const int ziffer4= 13;

int count=0;
int countto=0;

const byte numbers[10] = {
  0b10111110, // 0
  0b00110000, // 1
  0b10101101, // 2
  0b10111001, // 3
  0b00110011, // 4
  0b10011011, // 5
  0b10011111, // 6
  0b10110000, // 7
  0b10111111, // 8
  0b10111011  // 9
};

void setup()
{
  pinMode(PIN_STORE, OUTPUT);
  pinMode(PIN_SHIFT, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);

  pinMode(ziffer1, OUTPUT);
  pinMode(ziffer2, OUTPUT);
  pinMode(ziffer3, OUTPUT);
  pinMode(ziffer4, OUTPUT);
   Serial.begin(9600);

  digitalWrite(ziffer1,HIGH);
  digitalWrite(ziffer2,HIGH);
  digitalWrite(ziffer3,HIGH);
  digitalWrite(ziffer4,HIGH);
  
}

void loop(){

  timmer(count);

  countto +=4;
  if(countto>=1000){
    count +=1;
    countto = countto%1000;
  }

}

void timmer(int i_time){

  int tmp1=0;
  int tmp2=i_time;

  tmp1= tmp2 %10;
  tmp2 = tmp2/10;


  digitalWrite(ziffer4,LOW);
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, numbers[tmp1]);
  digitalWrite(PIN_STORE, HIGH);
  delay(1);
  digitalWrite(ziffer4,HIGH);
  

  tmp1= tmp2 %10;
  tmp2 = tmp2/10;

  digitalWrite(ziffer3,LOW);
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, numbers[tmp1]);
  digitalWrite(PIN_STORE, HIGH);
  delay(1);
  digitalWrite(ziffer3,HIGH);

    tmp1= tmp2 %10;
  tmp2 = tmp2/10;

  digitalWrite(ziffer2,LOW);
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, numbers[tmp1]);
  digitalWrite(PIN_STORE, HIGH);
  delay(1);
  digitalWrite(ziffer2,HIGH);
  
  tmp1= tmp2 %10;
  tmp2 = tmp2/10;

  digitalWrite(ziffer1,LOW);
  digitalWrite(PIN_STORE, LOW);
  shiftOut(PIN_DATA, PIN_SHIFT, LSBFIRST, numbers[tmp1]);
  digitalWrite(PIN_STORE, HIGH);
  delay(1);
  digitalWrite(ziffer1,HIGH);

}
