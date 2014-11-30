
#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>

#include "utils.h"
#include "shiftreg.h"
#include "unitable.h"
#include "matrixled.h"
#include "binarytable.h"

uint32_t static matrixled[8] = {0};

static int const cathode[8] = {0, 1, 2, 3, 4, 5, 6, 10};

static int cathodehigh(int row) {
	static int oldrow = 8;
	if (row == oldrow) return row;
	digitalWrite(cathode[oldrow], LOW);
	digitalWrite(cathode[row], HIGH);
	oldrow = row;
	return row;
}

int init_matrixled(void) {
	init_shiftreg();
	for (int i = 0; i < 8; i++) {
		pinMode (cathode[i], OUTPUT);
	}
	return 0;
}

static int display(void) {
	for (int i = 0;i < 8; i++) {
		send32(matrixled[i]);
		cathodehigh(i);
		delay(1);
	}
	return 0;
}

static int write_char(char const *c, size_t bit) {
	if (bit < 1 || 47 < bit || *c == '\0') {
		return 0;
	}

	int ismultibyte = (*(uint8_t const *)c) >> 7;
	int shift = 4 << ismultibyte;

	fontdata data = (ismultibyte?search_for_table:search_for_table4x8)(c);
	for (int i = 0; i < 8; i++) {
		if (bit < shift) {
			matrixled[i] &= (0xffffff00 | (0xf0 * !ismultibyte)) >> (shift - bit);
			matrixled[i] |= (0xffffffff & (((uint64_t)data.data[i]) >> (shift - bit)));
		} else {
			matrixled[i] &= (((0xffffff00  | (0xf0 * !ismultibyte)) <<  (bit - shift)) | ((0xffffff | (0xfffffff * !ismultibyte)) >> (32 - bit)));
			matrixled[i] |= (0xffffffff & (((uint64_t)data.data[i]) << (bit - 8)));
		}
	}
	return 0;
}

int mlprint(char const *str, int const velocity/* dot/sec */) {
	size_t length = utf8_strlen(str);
	write_char(str, 32);
	write_char(utf8_next_char(str), 24);
	write_char(utf8_next_char(utf8_next_char(str)), 16);
	write_char(utf8_next_char(utf8_next_char(utf8_next_char(str))), 8);
	display();
	return 0;
}
