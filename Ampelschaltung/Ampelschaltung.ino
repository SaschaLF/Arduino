//Coded by Sascha Spilewski
const int buzzerpin = 11;
const int trigger=12;
const int echo =13;

const int ledred=6;
const int ledgelb=7;
const int ledgruen=8;

long dauer=0;
long entfernung=0;
int buttonState =0;
bool ampelrot=false;
int timmer= 0;

void setup() {
  pinMode(buzzerpin,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(ledgruen,OUTPUT);
  pinMode(ledgelb,OUTPUT);
  pinMode(ledred,OUTPUT);
}

void loop() {
 

if(ampelrot ==false){
  
  timmer = 0;
  noTone(buzzerpin);
  
  digitalWrite(ledgruen,HIGH);
  delay(10000);
  digitalWrite(ledgruen,LOW);
  digitalWrite(ledgelb,HIGH);
  delay(1000);
  digitalWrite(ledgelb,LOW);
  digitalWrite(ledred,HIGH);
  
  ampelrot=true;
}
else{
  digitalWrite(trigger, LOW); 
  delay(5); 
  digitalWrite(trigger, HIGH); 
  delay(10); 
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH); 
  entfernung = (dauer/2) * 0.03432; 
  
  if (entfernung >= 10 || entfernung <= 0){
      noTone(buzzerpin);
  }
  else{
      tone(buzzerpin,200);
  }
  timmer +=15;
  
  if(timmer >=11000){
        digitalWrite(ledred,LOW);
    digitalWrite(ledgelb,LOW);
    ampelrot=false;
  }
 else if(timmer >=10000){
    
    digitalWrite(ledgelb,HIGH);
  }
  
}


  
  
}
