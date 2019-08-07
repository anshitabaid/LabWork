a=$1
op=$2
b=$3
res=0
case $op in 
"+")
res=`expr $a + $b`
;;
"-")
res=`expr $a - $b`
;;
"/")
res=`expr $a / $b`
;;
"*")
echo here
res=`expr $a \* $b`
;; 
esac
echo $res
