#ifndef FONTDATA_H
#define FONTDATA_H

#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint32_t unicode;
	uint8_t data[8];
} fontdata;

extern fontdata const table[];
extern size_t const tablesize;
extern size_t const tablebytes;

extern fontdata const table4x8[];
extern size_t const table4x8size;
extern size_t const table4x8bytes;

#endif
