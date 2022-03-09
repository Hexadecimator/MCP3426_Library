#include <Arduino.h>
#include <Wire.h> //include Wire.h library
#include <MCP3426_PING.h>

void delaySafeMillis(unsigned long timeToWait) {
	unsigned long start_time = millis();
	while (millis() - start_time <= timeToWait) {}
}

void setup() {
  Wire.begin(); // Wire communication begin
  
  Serial.begin(57600);
  while (!Serial); // Waiting for Serial Monitor
  
  Serial.println(F("[INFO] Welcome MCP3426 Communication Utility. Sending Config Packet..."));
  if(!initializeMCP3426()) for(;;) // couldn't init MCP3426 so we're done here
  
  delaySafeMillis(100); // give MCP3426 some time to settle
}

void loop() {
  uint8_t config       = readMCP3426Config();
  int16_t full_reading = readMCP3426CurrentBits();
  double  voltage      = readMCP3426CurrentVoltage();
  
  Serial.print(F("[INFO] Config = 0x"));
  Serial.print(config, HEX);
  Serial.print(F(" // Full Reading = 0x"));
  Serial.print(full_reading, HEX);
  Serial.print(F(" // Voltage = "));
  Serial.print(voltage);
  Serial.println(F(" Volts"));
  
  delaySafeMillis(1000); // don't blow up our serial monitor
}