awk -F\; 'BEGIN {printf("typedef struct {\n\tuint32_t unicode;\n\tuint8_t fontdata[8];\n} uni2jis;\nuni2jis table[] = {\n")} {print("\t{"$1", "$4"},") } END {print "\t{0x7fffffff, {0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa} }\n};"}' $1