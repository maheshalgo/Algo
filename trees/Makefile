
all : mytree
DEPS = algo_api.h
objects = trees.o create_bst.o moriss-tree.o queue.c stack.o
%.o : LIBFLAG = -ggdb -fPIC
%.o : CFLAG = -ggdb 
mytree : $(objects)
	gcc $(CFLAG) -o mytree $(objects) -lrt


