g++ -c Client/Client.cpp -o build/Client.o
g++ -c Server/Components.cpp -o build/Components.o
g++ -c Server/Server.cpp -o build/Server.o
g++ build/Client.o build/Components.o build/Server.o -o build/Main.exe
