// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>
void setup()
{
vw_set_ptt_inverted(true); // Required by the RF module
vw_setup(2000); // Transfer rate in bps
vw_set_tx_pin(4); // Transmitter DATA pin connected to Arduino digital pin 4
  pinMode(3, INPUT);
}
 
void loop()
{
  int movement = digitalRead(3);
const char *msg = "BEWEGUNG"; //Message to send
const char *no_msg = "KEINE BEWEGUNG";
if (movement == 1) {
vw_send((uint8_t *)msg, strlen(msg));
vw_wait_tx(); // Wait for message to finish sending
delay(200);
} else {
vw_send((uint8_t *)no_msg, strlen(no_msg));
vw_wait_tx(); // Wait for message to finish sending
delay(200);

}
}
