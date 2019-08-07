x=0
while [ $x -le 20 ]
do
	echo $x
	x=`expr $x + 1`
done
while test $# != 0
do
	echo $1
	shift
done

