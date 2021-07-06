CC = gcc
OBJ = test.o algorithm.o
APPDIR = ./app
APPNAME = test.exe
OBJDIR = ./obj

vpath %.c src
vpath %.h inc

test: $(OBJ)
	$(CC) -o $(APPDIR)/$(APPNAME) $(OBJ)
	mv ./*.o obj/

test.o : global.h TypeDefine.h algorithm.h Debug.h

algorithm.o : global.h TypeDefine.h Debug.h

.PHONY: clean
clean:
	-rm -fr $(OBJ)