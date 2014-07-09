#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int count = 0;
int row = 0;

String wordOut = "";

void setup(){
  //Begins the serial connection
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop(){
  
 if(Serial.available() > 0){      
        count++;
        
        //Jumps to 2nd line at the end of the first
        if(count == 17){
          lcd.setCursor(0,1);
          wordOut = "";
          row = 1;  
        }  
        
        char yep = Serial.read();

        wordOut = wordOut + yep;
        lcd.setCursor(0,row);
        lcd.print(wordOut);
        Serial.flush();
  }
  
}

