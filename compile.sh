echo Compiling...

g++-8 -o uva $1.cpp -D DBG
if [ "$?" == "0" ]; then
	echo Finished
	./uva
fi
