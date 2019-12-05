#include "PPMReaderSTM32.h"
/*
  https://www.onetransistor.eu/2019/05/arduino-class-interrupts-and-callbacks.html

*/

PPMReader ppmReader(PD7, false);

void setup()
{
  Serial.begin(115200);

  ppmReader.begin();
  //pinMode(LED_BUILTIN, OUTPUT);

  //ppmReader.begin(PD7);
  //ppmReader.setCallback(writePinStateToSerial);

  //while(!Serial.available());
  // Serial.println("ready");
}

void loop()
{
  int count;

  while (ppmReader.get(count) != 0) { //print out the servo values

    ppmReader.get(count);

    Serial.print("["); Serial.print(count); Serial.print("]  "); Serial.println(ppmReader.get(count));
    count++;
  }
  Serial.println("no or new entry ");

  delay(5); //you can even use delays!!!
}
