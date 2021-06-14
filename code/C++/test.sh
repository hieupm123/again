for((i = 1; ; ++i)); do
	echo "#"$i;
	./c $i > in;
	./b < in;
	./a < in;
done