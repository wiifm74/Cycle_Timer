#include <Cycle_Timer.h>

#define PUMP_WIRE_PWR 5						// Use GPIO pins for power to simplify the wiring
#define PUMP_WIRE_GND 6						// Use GPIO pins for ground to simplify the wiring

CycleTimer pumpController;

void setup() {

  pinMode(PUMP_WIRE_PWR, OUTPUT);
  pinMode(PUMP_WIRE_GND, OUTPUT);

  pumpController.setPin(PUMP_WIRE_PWR);
  pumpController.setOnTime(300);				// Set on time to 300ms
  pumpController.setOffTime(700);				// Set off time to 700ms

}

void loop() {
  
  pumpController.update();

}
