echo Compiling...

g++-7 -o uva $1.cpp -D DBG
if [ "$?" == "0" ]; then
	echo Finished
	./uva
fi
