#!/bin/bash
BINARYNAME=$(/usr/bin/file $(/usr/bin/ls -tr) |\
/usr/bin/grep -E -v "\.sh:|ASCII" |\
/usr/bin/grep executable |\
/usr/bin/sed "s/://;" |\
/usr/bin/awk 'END { print $1}')
echo $BINARYNAME
for num in {1..500}
do
	echo "============= START $num =============="
	$BINARYNAME
	echo "============= END T $num =============="
done
