/*
 *	File:		Cycle_Timer.h
 *	Title:  	Cycle_Timer.h
 *	Author(s):  wiifm
 *	Created:  	Feb 2016
 *	License:  	GNU General Public License v3
 *
 *	LICENSE:
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 3 of the License, or
 *	any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
*/


#ifndef CYCLE_TIMER_H_
#define CYCLE_TIMER_H_

#include <inttypes.h>

class CycleTimer {

public:
	CycleTimer(void);
	CycleTimer(uint8_t outputPin, int onMS, int offMS, uint8_t startingValue);
	void setPin(uint8_t outputPin);
	void setOnTime(int onMS);
	void setOffTime(int offMS);
	int getOnTime();
	int getOffTime();
	int getRemainingTime();
	void update();
	void update(unsigned long now);

private:
	uint8_t pin;
	uint8_t pinState = HIGH;
	unsigned long onTime = 0;
	unsigned long offTime = 0;
	unsigned long lastEventTime = 0;
};

#endif /* CYCLE_TIMER_H_ */
