#include <msp430.h>
#include "dht22.h"
#include <stdio.h>

char txbuf[256];

void uart_init() {
  UCA0CTL0 = 0;
  UCA0CTL1 |= UCSWRST; // Put USCI in reset mode
  UCA0CTL1 = UCSSEL_2 | UCSWRST; // Use SMCLK, still reset
  UCA0MCTL = UCBRF_0 | UCBRS_6;
  UCA0BR0 = 131; // 9600 bauds
  UCA0BR1 = 6;
  UCA0CTL1 &= ~UCSWRST; // Normal mode
	P1SEL2 |= (BIT1 + BIT2); // Set pins for USCI
	P1SEL |= (BIT1 + BIT2);
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
