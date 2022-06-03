#include "gd32vf103.h"
#include "drivers.h"
#include "lcd.h"
#include "usart.h"
#define EI 1
#define DI 0

int codeWrite(int key) //TX 
{
  int nextrow=0;
  switch(key)
  {
    case 0: usart_data_transmit(USART0, (0)+'0'); return 0; //TX (Transmitt) 0 
    case 1: usart_data_transmit(USART0, (1)+'0'); return 0; //TX (Transmitt) 1
    case 2: usart_data_transmit(USART0, (2)+'0'); return 0; //TX (Transmitt) 2
    case 3: usart_data_transmit(USART0, (3)+'0'); return 0; //TX (Transmitt) 3
    case 4: usart_data_transmit(USART0, (4)+'0'); return 0; //TX (Transmitt) 4
    case 5: usart_data_transmit(USART0, (5)+'0'); return 0; //TX (Transmitt) 5
    case 6: usart_data_transmit(USART0, (6)+'0'); return 0; //TX (Transmitt) 6
    case 7: usart_data_transmit(USART0, (7)+'0'); return 0; //TX (Transmitt) 7
    case 8: usart_data_transmit(USART0, (8)+'0'); return 0; //TX (Transmitt) 8
    case 9: usart_data_transmit(USART0, (9)+'0'); return 0; //TX (Transmitt) 9
    case 10: usart_data_transmit(USART0, (65)); return 0; //TX (Transmitt) A
    case 11: usart_data_transmit(USART0, (66)); return 0; //TX (Transmitt) B
    case 12: usart_data_transmit(USART0, (67)); return 0; //TX (Transmitt) C
    case 13: usart_data_transmit(USART0, (68) ); nextrow=20; return nextrow; //TX (Transmitt) D Next Row
  }
}

int numberComp(int key, int *temp1,int *temp2,int *temp3,int *temp4,int *checkLetter)
{
  switch(key) //Protocol Counter
  {
    case 0: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 1: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 2: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 3: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 4: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 5: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 6: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 7: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 8: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 9: *checkLetter=*checkLetter+1; return 0; //Counter +1
    case 10: *checkLetter=*checkLetter+1; if(*checkLetter==1){*temp1=*temp1+1;} if(*checkLetter!=1){*temp1=*temp1-1;} return 0; //Check Placement of A
    case 11: *checkLetter=*checkLetter+1; if(*checkLetter==2){*temp2=*temp2+1;} if(*checkLetter!=2){*temp1=*temp1-1;} return 0; //Check Placement of B
    case 12: *checkLetter=*checkLetter+1; if(*checkLetter==8){*temp3=*temp3+1;} if(*checkLetter!=8){*temp1=*temp1-1;} return 0; //Check Placement of C
    case 13: *checkLetter=*checkLetter+1; if(*checkLetter==11){*temp4=*temp4+1;} if(*checkLetter!=11){*temp1=*temp1-1;} //Check Placement of D & Check all other Placements 
    if(*temp1==1 && *temp2==1 && *temp3==1 && *temp4==1 ){*temp1=0; *temp2=0;*temp3=0;*temp4=0;*checkLetter=0; return 1;} //Reset for Next Read
    *temp1=0; *temp2=0;*temp3=0;*temp4=0;*checkLetter=0; return 0;
  }
}

int main(void){
    int ms=0, s=0, key, pKey=-1, c=0, idle=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0, speed=-100;
    int adcr, tmpr;
    char digits[10][10]={"Zero ","One  ","Two  ","Three","Four ","Five ","Six  ","Seven","Eight","Nine "};
    char msg[]="*";
    int counterX=0; int counterY=10; int returnCounter=0;
    int *temp1=0,*temp2=0,*temp3=0,*temp4=0;
    int *checkLetter=0;
    int okOrError;

    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolbox
    Lcd_SetType(LCD_NORMAL);                // or use LCD_INVERTED!
    Lcd_Init();
    LCD_Clear(BLACK);
    //LCD_ShowStr(10, 10, "POLL VERSION", WHITE, TRANSPARENT);
    u0init(EI);                             // Initialize USART0 toolbox

    eclic_global_interrupt_enable();        // !!! INTERRUPT ENABLED !!!

    while (1) {
        idle++;                             // Manage Async events
        LCD_WR_Queue();                     // Manage LCD com queue!
        u0_TX_Queue();                      // Manage U(S)ART TX Queue!

        if (usart_flag_get(USART0,USART_FLAG_RBNE)){ // USART0 RX?
          LCD_ShowChar(counterX,counterY,usart_data_receive(USART0), OPAQUE, WHITE); //RX - Read TX for X & Y Cordinates
          counterX=counterX+10; //Move X to the Right
          if(returnCounter>0) 
          {
            if(okOrError==0) //Show ERR
            {
              LCD_ShowChar(counterX+10,counterY,69, OPAQUE, WHITE);
              LCD_ShowChar(counterX+20,counterY,82, OPAQUE, WHITE);
              LCD_ShowChar(counterX+30,counterY,82, OPAQUE, WHITE);
            }
            if(okOrError==1) //Show OK!
            {
              LCD_ShowChar(counterX+10,counterY,79, OPAQUE, WHITE);
              LCD_ShowChar(counterX+20,counterY,75, OPAQUE, WHITE);
              LCD_ShowChar(counterX+30,counterY,33, OPAQUE, WHITE);
              okOrError=0; //Reset OK/ERR
            }          
              counterY=counterY+returnCounter; //Move Y Down
              counterX=0; //Move X to Start
          }
          returnCounter=0;
          if(counterY==30 && counterX==0){counterX=0;} //if D Pressed Next Row
          if(counterY==50 && counterX==0){counterX=0;} //if D Pressed Next Row
          if(counterX==160 && counterY==10){counterY=30; counterX=0;} //if Max X Length Pressed Next Row
          if(counterX==160 && counterY==30){counterY=50; counterX=0;} //if Max X Length Pressed Next Row
          if(counterX==160 && counterY==50){counterY=70; counterX=0;} //if Max X Length Pressed Next Row
        }

        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
            ms++;                           // ...One second heart beat
            if (ms==1000){
              ms=0;
              l88mem(0,s++);
              //LCD_ShowStr(10, 30, digits[s%10], WHITE, OPAQUE);
              //usart_data_transmit(USART0, (s%10)+'0'); // USRAT0 TX!
              //msg[0]=(s%10)+'0'; putstr(msg);
            }
            if ((key=keyscan())>=0) {       // ...Any key pressed?
              if (pKey==key) c++; else {c=0; pKey=key;}
              l88mem(1,lookUpTbl[key]+(c<<4));
              returnCounter=codeWrite(lookUpTbl[key]); //TX Function & Next Row if D
              okOrError=numberComp(lookUpTbl[key],&temp1,&temp2,&temp3,&temp4,&checkLetter); //Check for OK! or ERR
              if(counterY==70){counterY=10; LCD_Clear(BLACK); counterX=0;} //If Full Then Reset
            }
            l88mem(2,idle>>8);              // ...Performance monitor
            l88mem(3,idle); idle=0;
        }
    }
}