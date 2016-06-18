// receiver.pde
//
// Simple example of how to use VirtualWire to receive messages
// Implements a simplex (one-way) receiver with an Rx-B1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: receiver.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>

 
void setup()
{
Serial.begin(9600);
vw_set_ptt_inverted(true); // Required by the RF module
vw_setup(2000); // Transfer rate in bps
vw_set_rx_pin(4); // Receiver DATA pin connected to 2nd Arduino's digital pin 4
vw_rx_start();
}
 
void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
if (vw_get_message(buf, &buflen)) // Check if data received
{
int i;
for (i = 0; i < buflen; i++)
{
Serial.write(buf[i]);
/*Received data stored in buffer and sent to computer through the serial port*/
}
Serial.println();
}
}
