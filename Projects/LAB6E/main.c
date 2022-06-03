#include "gd32vf103.h"
#include "drivers.h"
#include "lcd.h"
#include "usart.h"
#define EI 1
#define DI 0

void txToRx(int key, char msg[],int *counter1,int *value1,int *value2,int *totalValue)
{
  switch(key)
  {
    case 0: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+0*16;} if(*counter1==1){ *value2=*value2+0; *totalValue=*value1+*value2;} //48 first input 48 -
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return;
    case 1: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+1*16;} if(*counter1==1){ *value2=*value2+1; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 2: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+2*16;} if(*counter1==1){ *value2=*value2+2; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 3: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+3*16;} if(*counter1==1){ *value2=*value2+3; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 4: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+4*16;} if(*counter1==1){ *value2=*value2+4; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 5: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+5*16;} if(*counter1==1){ *value2=*value2+5; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 6: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+6*16;} if(*counter1==1){ *value2=*value2+6; *totalValue=*value1+*value2;;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 7: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+7*16;} if(*counter1==1){ *value2=*value2+7; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 8: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+8*16;} if(*counter1==1){ *value2=*value2+8; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;} return; 
    case 9: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+9*16;} if(*counter1==1){ *value2=*value2+9; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;}  return;
    case 10: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+10*16;} if(*counter1==1){ *value2=*value2+10; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1;*value1=-1; *value2=-1;}  return;
    case 11: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+11*16;} if(*counter1==1){*value2=*value2+11; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1; *value1=-1; *value2=-1;}  return; 
    case 12: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+12*16;} if(*counter1==1){*value2=*value2+12; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1; *value1=-1; *value2=-1;}  return; 
    case 13: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+13*16;} if(*counter1==1){*value2=*value2+13; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1; *value1=-1; *value2=-1;}  return; 
    case 14: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+14*16;} if(*counter1==1){*value2=*value2+14; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1; *value1=-1; *value2=-1;}  return; 
    case 15: *counter1=*counter1+1; if(*counter1==0){*value1=*value1+15*16;} if(*counter1==1){*value2=*value2+15; *totalValue=*value1+*value2;}
     if(*counter1==1){usart_data_transmit(USART0, (*totalValue+2)); *counter1=-1; *totalValue=-1; *value1=-1; *value2=-1;}  return; //D6 LAST INPUT - 156 
  }
}

int main(void){
    int ms=0, s=0, key=-1 , pKey=-1, c=0, idle=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0, speed=-100;
    int adcr, tmpr;
    char digits[10][10]={"Zero ","One  ","Two  ","Three","Four ","Five ","Six  ","Seven","Eight","Nine "};
    char msg[]="*";
    int counterX=0; int counterY=10;
    int *value1=-1; int *value2=-1; int *counter1=-1; int *totalValue=-1;

    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolboxif(counterX==160 && counterY==10){counterY=30; counterX=0;}
    Lcd_SetType(LCD_NORMAL);                // or use LCD_INVERTED!
    Lcd_Init();
    LCD_Clear(BLACK);
    //LCD_ShowStr(10, 10, "POLL VERSION", WHITE, TRANSPARENT);
    u0init(EI);                             // Initialize USART0 toolbox

    eclic_global_interrupt_enable();        // !!! INTERRUPT ENABLED !!!

    while (1) {
        idle++;                             // Manage Async events
        LCD_WR_Queue();                     // Manage LCD com queue!
        //u0_TX_Queue();                      // Manage U(S)ART TX Queue

        if (usart_flag_get(USART0,USART_FLAG_RBNE)){ // USART0 RX?
          LCD_ShowChar(counterX,counterY,usart_data_receive(USART0), OPAQUE, WHITE); //76 A
          counterX=counterX+10;
          if(counterX==160 && counterY==10){counterY=30; counterX=0;}
          if(counterX==160 && counterY==30){counterY=50; counterX=0;}
        }

        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
            ms++;                           // ...One second heart beat
            if (ms==1000){
              ms=0;
              l88mem(0,s++);
              //LCD_ShowStr(10, 30, digits[s%10], WHITE, OPAQUE);
              //usart_data_transmit(USART0, (s%10)); // USRAT0 TX!
              //msg[0]=(s%10); putstr(msg);
            }
            if ((key=keyscan())>=0) {       // ...Any key pressed?
              if (pKey==key) c++; else {c=0; pKey=key;}
              l88mem(1,lookUpTbl[key]+(c<<4));
              txToRx(lookUpTbl[key],msg,&counter1,&value1,&value2,&totalValue);
            }
            l88mem(2,idle>>8);              // ...Performance monitor
            l88mem(3,idle); idle=0;
        }
    }
}