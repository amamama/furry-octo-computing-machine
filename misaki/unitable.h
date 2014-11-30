#ifndef UNITABLE_H
#define UNITABLE_H

#include <stdint.h>

typedef struct {
	uint32_t unicode;
	uint8_t fontdata[8];
} uni2jis;

#endif
