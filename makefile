64bit_float_to_hex: 64_bit_float_to_hex.o
	g++ -o 64bit_float_to_hex.exe 64bit_float_to_hex.o
	
64bit_float_to_hex.o: 64bit_float_to_hex.cpp
	g++ -c 64bit_float_to_hex.cpp -o 64bit_float_to_hex.o
	
clean:
	rm *.o
	rm *.exe