awk ' $3 != "" {printf("% 10d %s %s\n", strtonum("0x"$2), $1, $3)}' $1 |sort -n
