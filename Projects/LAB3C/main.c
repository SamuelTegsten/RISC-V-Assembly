#include "gd32vf103.h"
#include "drivers.h"
#include "dac.h"
#include "pwm.h"

void engineControl(int key, int *pthrottle)
{
  switch(key){
    case 1: 
    *pthrottle=(*pthrottle+25); 
    if(*pthrottle>=100){*pthrottle=100;}
    if(*pthrottle==0 || *pthrottle==25 || *pthrottle==50 || *pthrottle==75 || *pthrottle==100)
    { 
      T1powerUpInitPWM(0x2); 
      T1setPWMmotorB(*pthrottle);
      if(*pthrottle==0){T1setPWMch2(0); T1setPWMmotorB(0); l88mem(0,0); l88mem(1,120); l88mem(2,72); l88mem(3,126); l88mem(4,126); l88mem(5,66); l88mem(6,126);l88mem(7,0);} //B Stop
      if(*pthrottle==25){l88mem(0,0);l88mem(1,24); l88mem(2,24); l88mem(3,24); l88mem(4,24); l88mem(5,24); l88mem(6,24);l88mem(7,0);} //1 Forward
      if(*pthrottle==50){l88mem(0,0);l88mem(1,126); l88mem(2,2); l88mem(3,126); l88mem(4,126); l88mem(5,64); l88mem(6,126);l88mem(7,0);} //2 Forward
      if(*pthrottle==75){l88mem(0,0);l88mem(1,126); l88mem(2,2); l88mem(3,126); l88mem(4,126); l88mem(5,2); l88mem(6,126);l88mem(7,0);} //3 Forward
      if(*pthrottle==100){l88mem(0,0);l88mem(1,108); l88mem(2,108); l88mem(3,108); l88mem(4,126); l88mem(5,12); l88mem(6,12);l88mem(7,0);} //4 Forward
    }
    if(*pthrottle==0 || *pthrottle==-25 || *pthrottle==-50 || *pthrottle==-75 || *pthrottle==-100)
    {
      T1powerUpInitPWM(0x1); 
      T1setPWMmotorB(*pthrottle);
      if(*pthrottle==0){T1setPWMch2(0); T1setPWMmotorB(0); l88mem(0,0); l88mem(1,120); l88mem(2,72); l88mem(3,126); l88mem(4,126); l88mem(5,66); l88mem(6,126);l88mem(7,0);} //B Stop
      if(*pthrottle==-25){l88mem(0,255); l88mem(1,231); l88mem(2,231); l88mem(3,231); l88mem(4,231); l88mem(5,231); l88mem(6,231); l88mem(7,255);} //1 Reverse
      if(*pthrottle==-50){l88mem(0,255); l88mem(1,129); l88mem(2,253); l88mem(3,129); l88mem(4,129); l88mem(5,191); l88mem(6,129); l88mem(7,255);} //2 Reverse
      if(*pthrottle==-75){l88mem(0,255); l88mem(1,129); l88mem(2,253); l88mem(3,129); l88mem(4,129); l88mem(5,253); l88mem(6,129); l88mem(7,255);} //3 Reverse
      if(*pthrottle==-100){l88mem(0,255); l88mem(1,147); l88mem(2,147); l88mem(3,147); l88mem(4,129); l88mem(5,243); l88mem(6,243); l88mem(7,255);} //4 Reverse
    }
    return;

    case 2:  
    *pthrottle=0; 
    T1setPWMch2(0); 
    T1setPWMmotorB(0); 
    l88mem(0,0); l88mem(1,120); l88mem(2,72); l88mem(3,126); l88mem(4,126); l88mem(5,66); l88mem(6,126); l88mem(7,0); //B Stop
    return;

    case 3: 
    *pthrottle=(*pthrottle-25); 
    if(*pthrottle<=-100){*pthrottle=-100;}  
    if(*pthrottle==0 || *pthrottle==-25 || *pthrottle==-50 || *pthrottle==-75 || *pthrottle==-100)
    {
      T1powerUpInitPWM(0x1); 
      T1setPWMmotorB(*pthrottle);
      if(*pthrottle==0){T1setPWMch2(0); T1setPWMmotorB(0); l88mem(0,0); l88mem(1,120); l88mem(2,72); l88mem(3,126); l88mem(4,126); l88mem(5,66); l88mem(6,126);l88mem(7,0);} //B Stop
      if(*pthrottle==-25){l88mem(0,255); l88mem(1,231); l88mem(2,231); l88mem(3,231); l88mem(4,231); l88mem(5,231); l88mem(6,231); l88mem(7,255);} //1 Reverse
      if(*pthrottle==-50){l88mem(0,255); l88mem(1,129); l88mem(2,253); l88mem(3,129); l88mem(4,129); l88mem(5,191); l88mem(6,129); l88mem(7,255);} //2 Reverse
      if(*pthrottle==-75){l88mem(0,255); l88mem(1,129); l88mem(2,253); l88mem(3,129); l88mem(4,129); l88mem(5,253); l88mem(6,129); l88mem(7,255);} //3 Reverse 
      if(*pthrottle==-100){l88mem(0,255); l88mem(1,147); l88mem(2,147); l88mem(3,147); l88mem(4,129); l88mem(5,243); l88mem(6,243); l88mem(7,255);} //4 Reverse
    }
    if(*pthrottle==0 || *pthrottle==25 || *pthrottle==50 || *pthrottle==75 || *pthrottle==100)
    { 
      T1powerUpInitPWM(0x2); 
      T1setPWMmotorB(*pthrottle);
      if(*pthrottle==0){T1setPWMch2(0); T1setPWMmotorB(0); l88mem(0,0); l88mem(1,120); l88mem(2,72); l88mem(3,126); l88mem(4,126); l88mem(5,66); l88mem(6,126);l88mem(7,0);} //B Stop
      if(*pthrottle==25){l88mem(0,0);l88mem(1,24); l88mem(2,24); l88mem(3,24); l88mem(4,24); l88mem(5,24); l88mem(6,24);l88mem(7,0);} //1 Forward
      if(*pthrottle==50){l88mem(0,0);l88mem(1,126); l88mem(2,2); l88mem(3,126); l88mem(4,126); l88mem(5,64); l88mem(6,126);l88mem(7,0);} //2 Forward
      if(*pthrottle==75){l88mem(0,0);l88mem(1,126); l88mem(2,2); l88mem(3,126); l88mem(4,126); l88mem(5,2); l88mem(6,126);l88mem(7,0);} //3 Forward
      if(*pthrottle==100){l88mem(0,0);l88mem(1,108); l88mem(2,108); l88mem(3,108); l88mem(4,126); l88mem(5,12); l88mem(6,12);l88mem(7,0);} //4 Forward
    }
    return;
  }
}

int main(void){
    int ms=0, s=0, key;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0;
    int *pthrottle=0;
    T1setPWMch2(0);
    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolbox
    DAC0powerUpInit();                      // Initialize DAC0/PA4 toolbox
    while (1) {                
        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
            ms++;                           // ...One second heart beat
            if (ms==1000){
              ms=0;
            }
            if ((key=keyscan())>=0) {       // ...Any key pressed?
              engineControl(lookUpTbl[key],&pthrottle);
              DAC0set(dac++);                 // DAC0 Unit test         
        }
    }
}
}
/*

    l88mem(1,108); 4 frammåt
    l88mem(2,108);
    l88mem(3,108);
    l88mem(4,126);
    l88mem(5,12);
    l88mem(6,12);

    l88mem(0,255); 4 bakåt
    l88mem(1,147); 
    l88mem(2,147);
    l88mem(3,147);
    l88mem(4,129);
    l88mem(5,243);
    l88mem(6,243);
    l88mem(7,255);

    l88mem(1,24); 1 frammåt
    l88mem(2,24);
    l88mem(3,24);
    l88mem(4,24);
    l88mem(5,24);
    l88mem(6,24);

    l88mem(0,255); 1 bakåt
    l88mem(1,231); 
    l88mem(2,231);
    l88mem(3,231);
    l88mem(4,231);
    l88mem(5,231);
    l88mem(6,231);
    l88mem(7,255);

    l88mem(1,126); 2 frammåt
    l88mem(2,2);
    l88mem(3,126);
    l88mem(4,126);
    l88mem(5,64);
    l88mem(6,126);

    l88mem(0,255); 2 bakåt
    l88mem(1,129); 
    l88mem(2,253);
    l88mem(3,129);
    l88mem(4,129);
    l88mem(5,191);
    l88mem(6,129);
    l88mem(7,255);

    l88mem(1,126); 3 frammåt
    l88mem(2,2);
    l88mem(3,126);
    l88mem(4,126);
    l88mem(5,2);
    l88mem(6,126);

    l88mem(0,255); 3 bakåt
    l88mem(1,129); 
    l88mem(2,253);
    l88mem(3,129);
    l88mem(4,129);
    l88mem(5,253);
    l88mem(6,129);
    l88mem(7,255);
*/

