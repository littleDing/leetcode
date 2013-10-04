filename=`echo $@.cpp | sed 's/ /_/g'`

k=1
path=$filename
while [ -f $path ] ; do
  k=$((k+1))
  mkdir -p attemp$k
  path=attemp$k/$filename
done

[ $k == 1 ] || echo warning! this is attemp$k of $@

if [ -f $path ] ; then 
	echo "file exists! change another name"  >&2
else
	touch $path
	ddd=`date "+%Y-%m-%d %H:%M"`
	cat template.cpp | sed 's/from.*/from	'"$ddd"'/g' | sed 's/to.*/to   '"$ddd"'/g' | sed 's/Attemp #1/Attemp #'$k'/g' > $path
	git add $path
fi
