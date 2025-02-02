/*
PPMReader library based on https://github.com/Hasi123/read-any-ppm
Works with Servo library

Paweł (DzikuVx) Spychalski 2017
https://quadmeup.com

License: GNU GPL v3
*/

#ifndef PPMReaderSTM32_h
#define PPMReaderSTM32_h

#include "Arduino.h"

#define PPMREADER_PMM_CHANNEL_COUNT 16

class PPMReader
{
  public:
    PPMReader(int pin, bool useTimer);
    int get(uint8_t channel);
    static void handler();
    volatile static int ppm[PPMREADER_PMM_CHANNEL_COUNT];
    void start(void);
    void stop(void);
    bool isReceiving(void);
    void begin();//proper initialization
  private:
    int _pin;
    int _interrupt;
};

#endif