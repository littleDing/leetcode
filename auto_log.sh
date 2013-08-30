filename=`echo $@.cpp | sed 's/ /_/g'`

if [ -f $filename ] ; then 
	echo "file exists! change another name"  >&2
else
	touch $filename
	ddd=`date "+%Y-%m-%d %H:%M:%S"`
	cat template.cpp | sed 's/from.*/from	'"$ddd"'/g' | sed 's/to.*/to   '"$ddd"'/g' > $filename

	git add $filename
fi
