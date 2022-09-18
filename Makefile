bin/CodingSystem.exe: lib/Settings.o lib/Main_Menu.o \
lib/Encryption.o lib/CodingSystem.o
	g++ lib/Settings.o lib/Main_Menu.o lib/CodingSystem.o \
	lib/Encryption.o -o bin/CodingSystem.exe

lib/Settings.o: src/Settings.cpp
	g++ -c src/Settings.cpp -o lib/Settings.o

lib/Main_Menu.o: src/Main_Menu.cpp 
	g++ -c src/Main_Menu.cpp -o lib/Main_Menu.o

lib/Encryption.o: src/Encryption.cpp
	g++ -c src/Encryption.cpp -o lib/Encryption.o

lib/CodingSystem.o: src/CodingSystem.cpp 
	g++ -c src/CodingSystem.cpp -o lib/CodingSystem.o
