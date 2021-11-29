#include <msp430.h> 

#define tempIN BIT0;
#define lightIN BIT1;

int val[2];

int temp = 0;
int light = 0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

     //clock configure
     ADC10CTL1 = INCH_1 + CONSEQ_3;
     ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON;
     ADC10AE0 = BIT1 +BIT0;
     ADC10DTC1=0x02;

     while(1){
         ADC10CTL0 &= ~ENC;
         while(ADC10CTL1 & BUSY);
         ADC10CTL0 |= ENC + ADC10SC;
         ADC10SA = (unsigned int)val;
         light = val[0];
         temp = val[1];
         _delay_cycles(1000);
     }
}






