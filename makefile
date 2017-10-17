all: problem1.bin problem2.bin problem3.bin problem4.bin

problem1.bin: problem1.cpp
	g++ -o bin1 problem1.cpp

problem2.bin: problem2.cpp
	g++ -o bin2 problem2.cpp

problem3.bin: problem3.cpp
	g++ -o bin3 problem3.cpp

problem4.bin: problem4.cpp
	g++ -o bin4 problem4.cpp

clean:
	rm -f bin*
