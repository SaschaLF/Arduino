
#include "IRremote.h"

int receiver = 12; 

IRrecv irrecv(receiver);    
decode_results results;     

void setup()
{ 
  irrecv.enableIRIn(); // Start the receiver


  
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  
}

void loop()
{
  
if (irrecv.decode(&results))

  {
    switch(results.value)

    {

      case 0xFF30CF: // 1 button pressed
                      digitalWrite(8,LOW);
                      digitalWrite(7,HIGH);
                      delay(1000);
                      digitalWrite(7,LOW);
                      digitalWrite(6,HIGH);
                      delay(5000);
                      digitalWrite(7,HIGH);
                      delay(1000);
                      digitalWrite(6,LOW);
                      digitalWrite(7,LOW);
                      digitalWrite(8,HIGH);
                      
                     
                      break;

                      
      case 0xFF52AD:
                     digitalWrite(8,LOW);
                     digitalWrite(7,LOW);
                     digitalWrite(6,LOW);
    }
    
      irrecv.resume(); // receive the next value



  }  


}/* --end main loop -- */
