CPP = cl
LK = link
RM = del

CPPFLAGS = /nologo /std:c++17 /EHa /O2 /W3 /GL /c
LKFLAGS = /nologo /ltcg

OBJ = Main_Menu.obj Cryptology.obj CodingSystem.obj Encryption.obj

all: $(OBJ)
	$(LK) $(LKFLAGS) /out:CodingSystem.exe $**

Main_Menu.obj: src\$*.cpp
	$(CPP) $(CPPFLAGS) /Fo:$@ $**

Cryptology.obj: src\$*.cpp
	$(CPP) $(CPPFLAGS) /Fo:$@ $**

CodingSystem.obj: src\$*.cpp
	$(CPP) $(CPPFLAGS) /Fo:$@ $**

Encryption.obj: src\$*.cpp
	$(CPP) $(CPPFLAGS) /Fo:$@ $**

clean: 
	$(RM) *.obj
	$(RM) *.exe

test:
	.\CodingSystem.exe
