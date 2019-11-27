/**
 * \file
 * \brief Board related settings and functions
 */

#ifndef BOARD
#define BOARD

#include <string>
#include <array>
#include <chrono>
#include <thread>

#include "gpio/gpio.h"
#include "board_iface.hpp"

#define NEW_BOARD

// PIN NAMES
#ifndef NEW_BOARD
static const unsigned char DATA0 = 7;  //BCM 7  - PIN 26
static const unsigned char DATA1 = 0; //BCM 0 - PIN 27
static const unsigned char DATA2 = 1;  //BCM 1  - PIN 28
static const unsigned char DATA3 = 5;  //BCM 5  - PIN 29  
static const unsigned char DATA4 = 6;  //BCM 6  - PIN 31
static const unsigned char DATA5 = 12; //BCM 12 - PIN 32
static const unsigned char DATA6 = 13; //BCM 13 - PIN 33
static const unsigned char DATA7 = 16; //BCM 16 - PIN 36
#else
static const unsigned char DATA0 = 24; //BCM 24 - PIN 18
static const unsigned char DATA1 = 25; //BCM 25 - PIN 22
static const unsigned char DATA2 = 7; //BCM 7 - PIN 26
static const unsigned char DATA3 = 5; //BCM 5 - PIN 29
static const unsigned char DATA4 = 6; //BCM 6 - PIN 31
static const unsigned char DATA5 = 12; //BCM 12 - PIN 32
static const unsigned char DATA6 = 13; //BCM 13 - PIN 33
static const unsigned char DATA7 = 16; //BCM 16 - PIN 36
#endif
static const unsigned char CLOCK = 4; //BCM 4 - PIN 7
static const unsigned char TCO = 14;   //BCM 14 - PIN 8
static const unsigned char PI_OK = 15; //BCM 15 - PIN 10
static const unsigned char FAIL = 18; //BCM 18 - PIN 12
static const unsigned char RESET = 17; //BCM 17 - PIN 11
static const unsigned char BUTTON = 25; //BCM 25 - PIN 22

static const std::array<uint32_t, 8> DATA_POSITION{
  1UL << DATA0,
  1UL << DATA1,
  1UL << DATA2,
  1UL << DATA3,
  1UL << DATA4,
  1UL << DATA5,
  1UL << DATA6,
  1UL << DATA7
};

static const uint32_t CLOCK_POSITION = 1UL << CLOCK;
static const uint32_t TCO_POSITION = 1UL << TCO;
static const uint32_t PI_STATUS_POSITION = 1UL << PI_OK;
static const uint32_t FAIL_POSITION = 1UL << FAIL;
static const uint32_t BUTTON_POSITION = 1UL << BUTTON;


void pullGPIO(unsigned pin, unsigned high);
void initGPIOInput(unsigned pin);
void initGPIOOutput(unsigned pin);
void init(int sensorType);
void shutdown();
void setGPIOHigh(unsigned pin);
void setGPIOLow(unsigned pin);
void resetAllGPIO();
/**
 *  \brief sleep nanoseconds wit busy wait
 *
 *  @param ns - nanoseconds to sleep
 *
 *  During tests on Rpi3 with 32bit Raspbian it was found that this function:
 *
 *  with cycles = 1(ns=8) sleeps 8-25 ns on idle core
 *
 *  with cycles = 7(ns=55) sleeps 45-64 ns on idle core
 */
void busyWait(uint64_t ns);

unsigned int readAllGPIO();
BoardInterface bInterface;

#include "board.cpp"

#endif //BOARD
