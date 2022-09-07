bin/CodingSystem.exe: lib/Settings.o lib/CodingSystem.o
	g++ lib/Settings.o lib/CodingSystem.o -o bin/CodingSystem.exe

lib/Settings.o: src/Settings.cpp
	g++ -c src/Settings.cpp -o lib/Settings.o

lib/CodingSystem.o: src/CodingSystem.cpp 
	g++ -c src/CodingSystem.cpp -o lib/CodingSystem.o
