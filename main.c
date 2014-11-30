#include <wiringPi.h>
#include "matrixled.h"

int main(int argc, char *argv[]) {
	if (argc == 1) return 0;

	wiringPiSetup();
	init_matrixled();
	for(;114514;)
	mlprint(argv[1], 8);
	return 0;
}
