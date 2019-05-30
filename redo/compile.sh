echo Compiling...

g++ -o uva $1.cpp
if [ "$?" == "0" ]; then
	echo Finished
	./uva
fi
