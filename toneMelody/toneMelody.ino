#include "pitches.h"

// notes in the melody:
const int btn1 = 9;
const int btn2 = 10; 
const int ledPin =  11;  
long CTime,PTime;
bool check;
int state = 0;
int bstate = 0;
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int melody2[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
 //pinMode(btn1, INPUT);
}


//  // iterate over the notes of the melody:
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//
//    // to calculate the note duration, take one second divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000 / noteDurations[thisNote];
//    tone(8, melody[thisNote], noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(8);
//  }
//}

void loop() {
  // no need to repeat the melody.

 if(digitalRead(btn1) == LOW) state = 1;
 if(digitalRead(btn2) == LOW) state = 2;

     if(state == 1){
        for(int TN=0 ; TN < 8 ; TN++ ){
            tone(8, melody[TN], 500);
            PTime=millis();
            digitalWrite(ledPin,HIGH);
            check=false;
            while(!check){
              CTime=millis();
              if(CTime-PTime>500) digitalWrite(ledPin,LOW);
              if(CTime-PTime>650) check=true;
               if( digitalRead(btn2) == LOW) {state = 2; check=true;}

              }
             
      }
   }
      
   if(state == 2){
          for(int TN=0;TN<8;TN++){
              tone(8, melody2[TN], 500);
              PTime=millis();
              digitalWrite(ledPin,HIGH);
              check=false;
              while(!check){
                CTime=millis();
                if(CTime-PTime>500) digitalWrite(ledPin,LOW);
                if(CTime-PTime>650) check=true;
                if( digitalRead(btn1) == LOW ) {state = 1; check=true;}
                }
                 
        }
    }

}
