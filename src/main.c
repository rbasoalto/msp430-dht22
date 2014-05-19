#include <msp430.h>
#include "dht22.h"
#include <stdio.h>

char txbuf[256];

void uart_init() {
  UCA0CTL0 = 0;
  UCA0CTL1 |= UCSWRST;
  UCA0CTL1 = UCSSEL_2 + UCSWRST;
  UCA0MCTL = UCBRF_0 + UCBRS_6;
  UCA0BR0 = 131;
  UCA0BR1 = 6;
  UCA0CTL1 &= ~UCSWRST;
	P1SEL2 |= (BIT1 + BIT2);
	P1SEL |= (BIT1 + BIT2);
  P1DIR |= BIT0|BIT6;
  P1OUT &= ~(BIT0|BIT6);
}

void uart_send(int len) {
  int i;
  for(i = 0; i < len; i++) {
    while (UCA0STAT & UCBUSY);
    UCA0TXBUF = txbuf[i];
  }
}

int main() {
  WDTCTL = WDTPW | WDTHOLD;
  DCOCTL = 0;
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;
  BCSCTL3 = XCAP_2; // LFXT1 10pf caps


  uart_init();

  _BIS_SR(GIE);

  while(1) {
    dht_start_read();
    int t = dht_get_temp();
    int h = dht_get_rh();
    uart_send(sprintf(txbuf, "%3d.%1d C; %3d.%1d %%RH\r\n", t/10, t%10, h/10, h%10));
  }

  return 0;
}
