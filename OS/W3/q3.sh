echo "Enter  a b and c"
read a
read b
read c
d=`expr $b \* $b - 4 \* $a \* $c`
if [ $d == 0 ] 
then d1=0
else
d1=`expr $d / $d`
fi
echo $d1
r1=0
r2=0
case $d1 in
"0")
	echo "roots equal"
	r1=`expr -1 \* $b / \( 2 \* $a \)`
	r2=$r1
	;;
"1")
	echo "roots real and distinct"
	d=`expr sqrt \( $d \) | bc`
	r1=`expr \( -1 \* $b + $d \) / \( $2 \* $a \)`
	r2=`expr \( -1 \* $b - $d \) / \( $2 \* $a \)`
	;;
"-1")
	echo "roots imaginary"
	d= `expr $d \* - 1`
	d=`expr sqrt \( $d \)`
	r1 = `expr -1 \*  $b / \( 2 \* $a \)`
	r2 = `expr $d / \( 2 \* $a \)`
	;;
*)
	echo "nothing"
	;;
esac
echo $r1
echo $r2

