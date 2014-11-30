#include <wiringPi.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "shiftreg.h"

enum {
	SO = 7,
	SCK = 8,
	RCK = 9,
};

static int pulse(int pin) {
	digitalWrite(pin, LOW);
	digitalWrite(pin, HIGH);
	digitalWrite(pin, LOW);
	return pin;
}

static uint8_t send8(uint8_t data) {
	for (int i = 0; i < 8; i++) {
		digitalWrite(SO, data >> (7 - i) & 0x1);
		pulse(SCK);
	}
	return data;
}

uint32_t send32(uint32_t data) {
	for (int i = 0;i < sizeof(uint32_t)/sizeof(uint8_t);i++){
		send8((data >> ((3 - i) * 8)) & 0xff);
	}
	pulse(RCK);
	return data;
}

int init_shiftreg(void) {
	pinMode (SO, OUTPUT);
	pinMode (SCK, OUTPUT);
	pinMode (RCK, OUTPUT);
	return 0;
}
