/*
 *	File:		Cycle_Timer.cpp
 *	Title:  	Cycle_Timer.cpp
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

#include "Arduino.h"
#include "Cycle_Timer.h"

CycleTimer::CycleTimer(void){
	CycleTimer(22,1,1,HIGH);
	//pinState = HIGH;
}
CycleTimer::CycleTimer(uint8_t outputPin, int onMS, int offMS, uint8_t startingValue) {
	pin = outputPin;
	setOnTime(onMS);
	setOffTime(offMS);
}

void CycleTimer::setPin(uint8_t outputPin) {
	pin = outputPin;
}

void CycleTimer::setOnTime(int onMS) {
	if (onMS > 0) {
		onTime = onMS;
	}
	else onTime = 0;
}

void CycleTimer::setOffTime(int offMS) {
	if (offMS > 0) {
			offTime = offMS;
		}
		else offTime = 0;
}
int CycleTimer::getOnTime() {
	return (int) onTime;
}

int CycleTimer::getOffTime() {
	return (int) offTime;
}

int CycleTimer::getRemainingTime(){
	unsigned long now = millis();
	switch (pinState) {
	case HIGH:
		return (int) lastEventTime + onTime - now;
		break;
	case LOW:
		return (int) lastEventTime + offTime - now;
		break;
	}
}

void CycleTimer::update() {
	update(millis());
}

void CycleTimer::update(unsigned long now) {
	switch (pinState) {
	case HIGH:
		if ((unsigned long)(now - lastEventTime) >= onTime) {
			pinState = LOW;
			digitalWrite(pin, pinState);
			lastEventTime = now;
		}
		break;
	case LOW:
		if ((unsigned long)(now - lastEventTime) >= offTime) {
			pinState = HIGH;
			digitalWrite(pin, pinState);
			lastEventTime = now;
		}
		break;
	}

}

