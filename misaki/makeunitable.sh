#$1 makestruct.sh
#$2 maketable.sh | uni2jis.sh
awk 'FILENAME == ARGV[1] {RS = "";table[$1] = "0x"$2", 0x"$3", 0x"$4", 0x"$5", 0x"$6", 0x"$7", 0x"$8", 0x"$9} FILENAME == ARGV[2] {RS="\n"} FILENAME == ARGV[3] {printf ("0x%08x;0x%s;\"%s\";{%s} \n", $1,tolower($2),$3,table[tolower($2)]);}' $1 $0 $2
