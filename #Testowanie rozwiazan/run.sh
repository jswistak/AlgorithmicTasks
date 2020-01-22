for((i=1;i<=5000;i++))do
	echo $i
	./gen $i > in
	./a < in > out1
	./brute < in > out2 
	diff out1 out2 || break
	#diff <(./a < in> <(./brute < in) || break
done
