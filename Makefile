SRC1 = ..\src\acllib.c
SRC2 = $(filter-out editor.c, $(wildcard *.c))
INCLUDE_DIR = ..\src
LIB = gdi32 ole32 oleaut32 uuid winmm msimg32

editor :
	gcc $(SRC1) $(SRC2) $@.c -I$(INCLUDE_DIR) $(LIB:%=-l%) -DWINVER=0x0501 -o $@