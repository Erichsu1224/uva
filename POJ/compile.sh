echo Compiling...

g++ -o POJ $1.cpp
if [ "$?" == "0" ]; then
	echo Finished
	./POJ
fi
