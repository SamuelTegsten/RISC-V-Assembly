#include "gd32vf103.h"
#include "drivers.h"
#include "lcd.h"

void batteryLevel(key)
{
  switch(key)
  {
    case 0: LCD_Fill(10,50,20,70,RED); LCD_ShowChar(10,50,126,TRANSPARENT,BLACK); return;
    case 1: LCD_Fill(10,50,20,70,RED); LCD_ShowChar(10,50,127,TRANSPARENT,BLACK); return;
    case 2: LCD_Fill(10,50,20,70,RED); LCD_ShowChar(10,50,128,TRANSPARENT,BLACK); return;
    case 3: LCD_Fill(10,50,20,70,RED); LCD_ShowChar(10,50,129,TRANSPARENT,BLACK); return;
    case 4: LCD_Fill(10,50,20,70,RED); LCD_ShowChar(10,50,130,TRANSPARENT,BLACK); return;
  }
}

int main(void){
    int ms=0, s=0, key, pKey=-1, c=0, idle=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0, speed=-100;
    int adcr, tmpr;
    char digits[10][10]={"Zero ","One  ","Two  ","Three","Four ","Five ","Six  ","Seven","Eight","Nine "};

    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolbox
    Lcd_SetType(LCD_NORMAL);                // or use LCD_INVERTED!
    Lcd_Init();
    LCD_Clear(RED);
    LCD_ShowStr(10, 10, "POLL VERSION", WHITE, TRANSPARENT);
    //LCD_ShowChar(10,50,127,TRANSPARENT,BLACK); //127

    while (1) {
        idle++;                             // Manage Async events
        LCD_WR_Queue();                   // Manage LCD com queue!

        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
            ms++;                           // ...One second heart beat
            if (ms==1000){
              ms=0;
              l88mem(0,s++);
              LCD_ShowStr(10, 30, digits[s%10], WHITE, OPAQUE);
            }
            if ((key=keyscan())>=0) {       // ...Any key pressed?
              if (pKey==key) c++; else {c=0; pKey=key;}
              l88mem(1,lookUpTbl[key]+(c<<4));
              batteryLevel(lookUpTbl[key]);
            }
            l88mem(2,idle>>8);              // ...Performance monitor
            l88mem(3,idle); idle=0;
        }
    }
}