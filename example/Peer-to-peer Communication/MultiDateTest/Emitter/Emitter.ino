//Transmitter program

#include "Mirf.h"

Nrf24l Mirf = Nrf24l(10, 9);

byte value[4];

void setup()
{
  Serial.begin(115200);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  //Set your own address (sender address) using 5 characters
  Mirf.setTADDR((byte *)"Motor");
  Mirf.payload = sizeof(value);
  Mirf.channel = 90;              //Set the channel used
  Mirf.config();
}

void loop()
{
  value[0] = 0;
  value[1] = 1;
  value[2] = 2;
  value[3] = random(255);                      //0-255 random number
  Mirf.send(value);                //Send instructions, send random number value
  Serial.print("Wait for sending.....");
  //Test you send successfully
  if (Mirf.isSend()) {
    Serial.print("Send success:");
    Serial.println(value[3]);
  } else {
    Serial.println("Send fail:");
  }
  delay(1000);
}
