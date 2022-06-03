#include "gd32vf103.h"
#include "drivers.h"
#include "dac.h"
#include "pwm.h"
#include "adc.h"
#include "eclicw.h"

void mt40k_init(void (*pISR)(void)){
   eclicw_enable(CLIC_INT_TMR, 1, 1, pISR);
   // Set the timer expier (compar) value to 675 (27Mhz/40kHz).
   *( volatile uint64_t * )( TIMER_CTRL_ADDR + TIMER_MTIMECMP ) = 675;
   // Reset the timer value to zero.
   *( volatile uint64_t * )( TIMER_CTRL_ADDR + TIMER_MTIME ) = 0;
}
/*
void lp(void){
    static int x=0;

    // Be aware of possible spirous int updating mtimecmp...
    // LSW = -1; MSW = update; LSW = update, in this case safe.
    *( volatile uint64_t * )( TIMER_CTRL_ADDR + TIMER_MTIMECMP )+=675;

    // Calcylate next output value...
    DAC0set(x++%2?4000:0);
    l88mem(7,x);
}
*/

void lp(void){
    static int x=0, xp=0, y=0, yp=0;
    static int g=0b0010001100000000; //0.1367287359(<<16)
    static int p=0b1011100111111110; //0.7265425280(<<16)

    // Be aware of possible spirous int updating mtimecmp...
    // LSW = -1; MSW = update; LSW = update, in this case safe.
    *( volatile uint64_t * )( TIMER_CTRL_ADDR + TIMER_MTIMECMP )+=675;

    // Calcylate next output value...
    xp=x; yp=y;
    x = ((adc_regular_data_read(ADC0)-2048))*g;
    y = (x+xp)+(int)(((int64_t)yp*(int64_t)p)>>16);
    DAC0set((y>>16)+2048);              // ...and present it to hw-driver.

    adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);
}

int main(void){
    int ms=0, sec=0, key, pKey=-1, c=0, idle=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int dac=0, speed=-100;
    int adcr, tmpr;
    int temperature;
    int totalTemperature;
    int temp1=0,temp2=0,temp3=0,temp4=0,temp5=0,temp6=0,temp7=0,temp8=0;
    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();                              // Initialize keyboard toolbox
    ADC3powerUpInit(1);                     // Initialize ADC0, Ch3 & Ch16

    while (1) {
        idle++;                             // Manage Async events

        if (t5expq()) {                     // Manage periodic tasks
            l88row(colset());               // ...8*8LED and Keyboard
          if (adc_flag_get(ADC0,ADC_FLAG_EOC)==SET) { // ...ADC done?
          if (adc_flag_get(ADC0,ADC_FLAG_EOIC)==SET) { //...ch3 or ch16?
            tmpr = adc_inserted_data_read(ADC0, ADC_INSERTED_CHANNEL_0);
            //l88mem(0,((0x680-tmpr)/5)+25);
            adc_flag_clear(ADC0, ADC_FLAG_EOC);
            adc_flag_clear(ADC0, ADC_FLAG_EOIC);
          } else {
            adcr = adc_regular_data_read(ADC0); // ......get data
            adc_flag_clear(ADC0, ADC_FLAG_EOC); // ......clear IF
          }
        }      
            temperature =(((0x680-tmpr)/5)+25);
            totalTemperature = totalTemperature + temperature;                     // ...One second heart beat
            ms++;
            if (ms==1000){
              ms=0;
              if(sec==0){ //1 seconds
                totalTemperature = totalTemperature / 1000; 
                temp1 = totalTemperature; //temporary saving 1
                l88mem(0,totalTemperature); /* <-- Current reading & Previous reading --> */ l88mem(1,temp8); l88mem(2,temp7); l88mem(3,temp6); l88mem(4,temp5); l88mem(5,temp4); l88mem(6,temp3); l88mem(7,temp2); 
              }
                if(sec==1){ //2 second
                totalTemperature = totalTemperature / 1000; 
                temp2 = totalTemperature; //temporary saving 2
                l88mem(0,totalTemperature); l88mem(1,temp1); /* <-- Current reading & Previous reading --> */ l88mem(2,temp8); l88mem(3,temp7); l88mem(4,temp6); l88mem(5,temp5); l88mem(6,temp4); l88mem(7,temp3);
              }
              if(sec==2){ //3 seconds
                totalTemperature = totalTemperature / 1000; 
                temp3 = totalTemperature; //temporary saving 3
                l88mem(0,totalTemperature); l88mem(1,temp2); l88mem(2,temp1); /* <-- Current reading & Previous reading --> */ l88mem(3,temp8); l88mem(4,temp7); l88mem(5,temp6); l88mem(6,temp5); l88mem(7,temp4);
              }
              if(sec==3){ //4 seconds
                totalTemperature = totalTemperature / 1000; 
                temp4 = totalTemperature; //temporary saving 4
                l88mem(0,totalTemperature); l88mem(1,temp3); l88mem(2,temp2); l88mem(3,temp1); /* <-- Current reading & Previous reading --> */ l88mem(4,temp8); l88mem(5,temp7); l88mem(6,temp6); l88mem(7,temp5);
              }
              if(sec==4){ //5 seconds
                totalTemperature = totalTemperature / 1000; 
                temp5 = totalTemperature; //temporary saving 5
                l88mem(0,totalTemperature); l88mem(1,temp4); l88mem(2,temp3); l88mem(3,temp2); l88mem(4,temp1); /* <-- Current reading & Previous reading --> */ l88mem(5,temp8); l88mem(6,temp7); l88mem(7,temp6);
              }
              if(sec==5){ //6 seconds
                totalTemperature = totalTemperature / 1000; 
                temp6 = totalTemperature; //temporary saving 6
                l88mem(0,totalTemperature); l88mem(1,temp5); l88mem(2,temp4); l88mem(3,temp3); l88mem(4,temp2); l88mem(5,temp1); /* <-- Current reading & Previous reading --> */ l88mem(6,temp8); l88mem(7,temp7);
              }
              if(sec==6){ //7 seconds
                totalTemperature = totalTemperature / 1000; 
                temp7 = totalTemperature; //temporary saving 7
                l88mem(0,totalTemperature); l88mem(1,temp6); l88mem(2,temp5); l88mem(3,temp4); l88mem(4,temp3); l88mem(5,temp2); l88mem(6,temp1); /* <-- Current reading & Previous reading --> */ l88mem(7,temp8);
              }
              if(sec==7){ //8 seconds
                totalTemperature = totalTemperature / 1000; 
                temp8 = totalTemperature; //temporary saving 8
                l88mem(0,totalTemperature); l88mem(1,temp7); l88mem(2,temp6); l88mem(3,temp5); l88mem(4,temp4); l88mem(5,temp3); l88mem(6,temp2); l88mem(7,temp1); /* Final reading */
                sec = -1; // Repeat
              }
              totalTemperature = 0; //set temperature reading to 0
              sec++; //Count +1/s
              if ((key=keyscan())>=0) {       // ...Any key pressed?
              if (pKey==key) c++; else {c=0; pKey=key;}
              }
            adc_software_trigger_enable(ADC0, //Trigger another ADC conversion!
                                        ADC_REGULAR_CHANNEL);
        }
    }
}
}