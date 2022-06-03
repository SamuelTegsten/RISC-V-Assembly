#include "gd32vf103.h"
#include "drivers.h"
#include "lcd.h"

void drawing(int key,int *x1,int *y1,int *x2,int *y2,int *counter1,int *counter2,int *colourCounter,int *colourDisplay,int *colourchoice)
{
  switch(key)
  {
    case 0: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+1;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+1;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+1;} if(*counter2==1){*x2=*x2+1;}} //CORDINATES X2,Y2 
      if(*colourCounter==0){*colourchoice=*colourchoice+0;} return; 

    case 1: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+17;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+9;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+9;} if(*counter2==1){*x2=*x2+17;}} //CORDINATES X2,Y2 
      if(*colourCounter==0){*colourchoice=*colourchoice+1;} return; 

    case 2: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+33;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+17;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+17;} if(*counter2==1){*x2=*x2+33;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+2;} return; 

    case 3: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+49;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+25;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+25;} if(*counter2==1){*x2=*x2+49;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+3;} return; 

    case 4: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+65;} if(*counter1==1 && *y2==-1  || *counter1==3 && *y1==-1){*y1=*y1+33;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+33;} if(*counter2==1){*x2=*x2+65;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+4;} return; 

    case 5: *counter1=*counter1+1; //COUNT UP +1 
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+81;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+41;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+41;} if(*counter2==1){*x2=*x2+81;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+5;} return; 

    case 6: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+97;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+49;} //CORDINATES X1,Y1  
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+49;} if(*counter2==1){*x2=*x2+97;}} //CORDINATES X2,Y2 
      if(*colourCounter==0){*colourchoice=*colourchoice+6;} return; 

    case 7: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+113;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+57;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*x2=*y2+57;} if(*counter2==1){*y2=*x2+113;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+7;} return; 

    case 8: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1 || *counter1==2 && *x1==-1){*x1=*x1+129;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+65;} //CORDINATES X1,Y1 
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+65;} if(*counter2==1){*x2=*x2+129;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+8;} return; 

    case 9: *counter1=*counter1+1; //COUNT UP +1
      if(*counter1==5){*counter1=0;*x1=-1;*y1=-1;*counter2=-1;*x2=-1;*y2=-1; *colourCounter=-1; *colourchoice=0; *colourDisplay=0;} //RESET PREVIOUS READ
      if(*counter1==0 && *x2==-1|| *counter1==2 && *x1==-1){*x1=*x1+160;} if(*counter1==1 && *y2==-1 || *counter1==3 && *y1==-1){*y1=*y1+81;} //CORDINATES X1,Y1  
      if(*counter2>-1){*counter2=*counter2+1; if(*counter2==2){*y2=*y2+81;} if(*counter2==1){*x2=*x2+160;}} //CORDINATES X2,Y2
      if(*colourCounter==0){*colourchoice=*colourchoice+9;} return;  

    case 10: if(*x2==-1){*counter2=0;} if(*x2>-1){*colourCounter=0;} return; //A 1 REGISTER
    
    case 11: if(*counter2==-1){*x2=*x1; *y2=*y1; *y1=-1; *x1=-1;} if(*x1>-1){*colourCounter=0;} return; //B 2 REGISTER

    case 12: if(*colourCounter<0){*counter1=-1; *counter2=-1; *x1=-1; *y1=-1; *x2=-1; *y2=-1; return;}
             if(*colourchoice==0){*colourDisplay=65535; return;}//WHITE
             if(*colourchoice==1){*colourDisplay=65504; return;}//YELLOW
             if(*colourchoice==2){*colourDisplay=63519; return;}//BRED
             if(*colourchoice==3){*colourDisplay=48192; return;}//BROWN
             if(*colourchoice==4){*colourDisplay=0; return;}//BLACK
             if(*colourchoice==5){*colourDisplay=31; return;}//BLUE
             if(*colourchoice==6){*colourDisplay=2016; return;}//GREEN
             if(*colourchoice==7){*colourDisplay=32767; return;}//CYAN
             if(*colourchoice==8){*colourDisplay=33840; return;}//GRAY
             if(*colourchoice==9){*colourDisplay=463; return;}//DARK BLUE

    case 13: LCD_DrawLine(*x1,*y1,*x2,*y2,*colourDisplay); return; //DRAW LINE
    case 14: /*LCD_ShowStr(140, 60, "ST", WHITE, TRANSPARENT);*/ Draw_Circle(*x1,*y1,*y2,*colourDisplay); return; //SIGNATURE + CIRCLE
    case 15: LCD_Fill(*x1,*y1,*x2,*y2,*colourDisplay); return; //RECTANGLE
             /*LCD_Clear(RED); *colourDisplay=0; *counter1=-1; *counter2=-1;  *colourCounter=-1; *x1=-1,*y1=-1,*x2=-1,*y2=-1; return; //DELETE*/ 
               
  }
}

int main(void){
    int ms=0, s=0, key, pKey=-1, c=0, idle=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0, speed=-100;
    int adcr, tmpr;
    int *x1=-1,*y1=-1,*x2=-1,*y2=-1; 
    int *colourCounter=-1;
    int *colourDisplay=0;
    int *colourchoice=0;
    int *counter1=-1, *counter2=-1;
    //char digits[10][10]={"Zero ","One  ","Two  ","Three","Four ","Five ","Six  ","Seven","Eight","Nine "};

    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolbox
    Lcd_SetType(LCD_NORMAL);                // or use LCD_INVERTED!
    Lcd_Init();
    LCD_Clear(RED);
    //LCD_ShowStr(10, 10, "POLL VERSION", WHITE, TRANSPARENT);
    //LCD_ShowChar(10,50,127,TRANSPARENT,BLACK); //127

    while (1) {
        idle++;                             // Manage Async events
        LCD_WR_Queue();                   // Manage LCD com queue!

        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
            ms++;                           // ...One second heart beat
            if (ms==1000){
              ms=0;
              //l88mem(0,s++);
              //LCD_ShowStr(10, 30, digits[s%10], WHITE, OPAQUE);
            }
            if ((key=keyscan())>=0) {       // ...Any key pressed?
              //if (pKey==key) c++; else {c=0; pKey=key;}
              l88mem(1,lookUpTbl[key]+(c<<4));
              drawing(lookUpTbl[key],&x1,&y1,&x2,&y2,&counter1,&counter2,&colourCounter,&colourDisplay,&colourchoice);
            }
            //l88mem(2,idle>>8);              // ...Performance monitor
            //l88mem(3,idle); idle=0;
        }
    }
}