driver.o: driver.cpp bitarray.o set.o dictionary.o
	g++ driver.cpp bitarray.o set.o dictionary.o -o blah
	
bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o
	
set.o: set.cpp
	g++ -c set.cpp -o set.o
	
dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o
	
clean:
	rm -f bitarray.o set.o dictionary.o