read l
for file in `ls`
do
	echo "For $file $l occurs ` grep -c  $l $file ` times"
	#grep -c $l $file
done

#read $l
#grep -c $l *
