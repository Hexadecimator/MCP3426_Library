#ifndef MCP3426_H
#define MCP3426_H

#include <Arduino.h> // i think we need this for the typedefs

bool    initializeMCP3426(bool debug=false);
int16_t readMCP3426CurrentBits();
uint8_t readMCP3426Config();
double  readMCP3426CurrentVoltage();

#endif