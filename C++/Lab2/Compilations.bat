g++ -c Client/Client.cpp -o build/Client.o
g++ -c Server(Components)/ComplexNumbers.cpp -o build/ComplexNumbers.o
g++ -c Server(Components)/iUnknown.cpp -o build/iUnknown.o
g++ build/Client.o build/ComplexNumbers.o build/iUnknown.o -o build/Main.exe
