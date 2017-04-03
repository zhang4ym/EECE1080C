test: all
	/bin/bash ./testing/Check_all

all: filecopy caesar rot13 sub

filecopy: filecopy.cpp
	g++ -std=c++11 -DTESTING -o filecopy filecopy.cpp
caesar: caesar.cpp
	g++ -std=c++11 -DTESTING -o caesar caesar.cpp
rot13: rot13.cpp
	g++ -std=c++11 -DTESTING -o rot13 rot13.cpp
sub: sub.cpp
	g++ -std=c++11 -DTESTING -o sub sub.cpp
clean:
	rm -f sub rot13 caesar filecopy

