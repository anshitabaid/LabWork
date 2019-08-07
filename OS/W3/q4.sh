n=$1
prod=1
while test $n -gt 1
do
prod=`expr $prod \* $n`
n=`expr $n - 1`
done
echo $prod
