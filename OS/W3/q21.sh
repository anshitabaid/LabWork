x=$1
num=1
while test $x -lt $1
do
echo $num
num=`expr $num + 2`
x=`expr $x + 1`
done
