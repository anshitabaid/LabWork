stop=0
while test $stop -eq 0
do
cat << ENDOFMENU
1: print the date
2, 3: print cwd
4: exit
ENDOFMENU
echo
echo "Your choice?"
read reply
echo
case $reply in 
"1")
date
;;
"2"|"3")
pwd
;;
"4")
stop=1
;;
*)
echo "illegal choice"
;;
esac
done
