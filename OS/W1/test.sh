cd
ls $1 
for files in $(cd $1);
do
if [ $file == *.? ]; then echo $file; fi;
done;
