#include <stdlib.h>
#include <stdio.h>

#include "unitable.h"
#include "utils.h"
#include "fontdata.h"

static int compkey(void const *key1, void const *key2) {
	uint32_t const *utf8_char = (uint32_t const *)key1;
	fontdata const *data = (fontdata const *)key2;
	return (*utf8_char) - (data->unicode);
}

fontdata search_for_table(char const *utf8_char) {
	uint32_t key = 0;
	for(char const *next_char = utf8_next_char(utf8_char);utf8_char < next_char; utf8_char++) {
		key<<=8;
		key += *(uint8_t*)utf8_char;
	}
	return *(fontdata*)bsearch(&key, table, tablebytes / tablesize, tablesize, compkey);
}

fontdata search_for_table4x8(char const *ascii_char) {
	uint32_t key = *ascii_char;
	return *(fontdata*)bsearch(&key, table4x8, table4x8bytes / table4x8size, table4x8size, compkey);
}

