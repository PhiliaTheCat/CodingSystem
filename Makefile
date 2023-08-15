bin/CodingSystem.exe: lib/Settings.lib lib/Main_Menu.lib \
	lib/Encryption.lib lib/Cryptology.lib lib/CodingSystem.lib
	g++ lib/Settings.lib lib/Main_Menu.lib \
		lib/Encryption.lib lib/Cryptology.lib lib/CodingSystem.lib \
		-o bin/CodingSystem.exe

lib/Settings.lib: src/Settings.cpp
	g++ -c src/Settings.cpp -o lib/Settings.lib

lib/Main_Menu.lib: src/Main_Menu.cpp 
	g++ -c src/Main_Menu.cpp -o lib/Main_Menu.lib

lib/Encryption.lib: src/Encryption.cpp
	g++ -c src/Encryption.cpp -o lib/Encryption.lib

lib/Cryptology.lib: src/Cryptology.cpp
	g++ -c src/Cryptology.cpp -o lib/Cryptology.lib

lib/CodingSystem.lib: src/CodingSystem.cpp 
	g++ -c src/CodingSystem.cpp -o lib/CodingSystem.lib

run: bin/CodingSystem.exe
	./bin/CodingSystem.exe
	