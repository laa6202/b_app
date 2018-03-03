#CC=arm-linux-gcc
CC=gcc
TAR=b_app
SRC=file_op.c arg.c main.c action.c \
		source.c
OBJ=file_op.o arg.o main.o action.o \
		source.o
LIBDIR=
INCDIR=inc 
OPRDIR=aaa aaa_out

$(TAR) : $(OBJ)
	$(CC) -o $@ $^

$(OBJ) : $(SRC)
	$(CC) -c $^ -I $(INCDIR)

clean : 
	rm -rf $(TAR) $(OBJ) $(OPRDIR)


