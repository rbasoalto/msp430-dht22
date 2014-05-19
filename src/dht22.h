#ifndef __DHT_22_H__
#define __DHT_22_H__

#include <stdint.h>

typedef union {
  struct {
    uint8_t hh;
    uint8_t hl;
    uint8_t th;
    uint8_t tl;
    uint8_t crc;
  } val;
  uint8_t bytes[5];
} dht22data;

void dht_start_read();
int dht_get_temp();
int dht_get_rh();

#endif
