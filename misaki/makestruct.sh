awk 'NR  == 1 {while($1 != "CHARS") getline; RS = "ENDCHAR\n";FS="BITMAP\n";NR=1;print "0000 \n"} NR > 1 {fstline=substr($1, 1, index($1, "\n"));print substr(fstline, index(fstline, " ")+1)$2}' $1
#| 
#awk 'BEGIN {RS=""} {printf("\
#{\n\
#.jis = % 4s,\n\
#.fontdata = \n\
#\t{\n\
#\t\t%02s,\n\
#\t\t%02s,\n\
#\t\t%02s,\n\
#\t\t%02s,\n\
#\t\t%02s,\n\
#\t\t%02s,\n\
#\t\t%02s,\n\
#\t\t%02s\n\
#\t}\n\
#}\n\
#",$1, $2, $3, $4, $5, $6, $7, $8, $9)} ' 
