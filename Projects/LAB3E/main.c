#include "gd32vf103.h"
#include "drivers.h"
#include "dac.h"
#include "pwm.h"

int lightControl(int key,int *lightPower,int *counter,int *registerOne,int *registerTwo)
{
  switch(key){ //Control Values for Percentage 0-9 --> Max Value 100%, Don't Care 10-12, 13 Load Value, 14 Last Value Removed, 15 Remove All Read Values
    
    case 0: if(*counter>-1){(*counter=*counter+1); *lightPower=*lightPower+(0*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;}} return; //0+%
    case 1: (*counter=*counter+1); *lightPower=*lightPower+(1*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //1+%
    case 2: (*counter=*counter+1); *lightPower=*lightPower+(2*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //2+%
    case 3: (*counter=*counter+1); *lightPower=*lightPower+(3*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //3+%
    case 4: (*counter=*counter+1); *lightPower=*lightPower+(4*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //4+%
    case 5: (*counter=*counter+1); *lightPower=*lightPower+(5*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //5+%
    case 6: (*counter=*counter+1); *lightPower=*lightPower+(6*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //6+%
    case 7: (*counter=*counter+1); *lightPower=*lightPower+(7*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //7+%
    case 8: (*counter=*counter+1); *lightPower=*lightPower+(8*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //8+%
    case 9: (*counter=*counter+1); *lightPower=*lightPower+(9*160); if(*counter==0){*registerOne=*lightPower;} if(*counter==3){*counter=2;} return; //9+%
    case 10: return;
    case 11: return;
    case 12: return;
    case 13: if(*counter==-1) //Load Value
    {
      T1setPWMch2(0);
    }
    if(*counter==0) //Load 1:st Value
    {
      T1setPWMch2(*registerOne);
      *lightPower=0;
    } 
    if(*counter==1) //Load 2:nd Value
    {
      *registerOne=(*registerOne * 10);
      *registerTwo=(*lightPower + *registerOne);
      T1setPWMch2(*registerTwo);
      *lightPower=0;
      *registerOne=(*registerOne / 10);
    } 
    if(*counter==2) //Load 3:rd Value, Allways 100%
    {
      T1setPWMch2(15998);
    }  
    return;
    case 14: if(*counter==0) //Remove Last Value
    {
      *registerOne=0;
      *lightPower=0;
      *counter=-1;
    } 
    if(*counter==1)
    {
      *registerTwo=0;
      *lightPower=0;
      *counter=0;
    } 
    if(*counter==2)
    {
      *counter=1;
    } 
    return;
    case 15: T1setPWMch2(0); //Remove All Read Values
      *counter=-1; 
      *registerOne=0;
      *registerTwo=0;
      return;             
  } 

}

int main(void){
    int ms=0, s=0, key, pKey=-1, c=0;
    int *lightPower=0;
    int *counter=-1;
    int *registerOne=0;
    int *registerTwo=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0, speed=-100;

    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolbox
    DAC0powerUpInit();                      // Initialize DAC0/PA4 toolbox
    T1powerUpInitPWM(0x1);                  // Timer #1, Ch #2 PWM
    T1powerUpInitPWM(0x1);                  // Timer #1, Ch #2 & 3 PWM
    T1setPWMch2(0);

    while (1) {
 
        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
            ms++;                           // ...One second heart beat
            if (ms==1000){
              ms=0;
              l88mem(0,s++);
            }
            if ((key=keyscan())>=0) {       // ...Any key pressed?
              l88mem(1,lookUpTbl[key]);
              lightControl(lookUpTbl[key],&lightPower,&counter,&registerOne,&registerTwo);
            }
            DAC0set(dac++);                 // DAC0 Unit test
        }
    }
}