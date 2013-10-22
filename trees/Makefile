
all : mytree cleanobj
DEPS = algo_api.h
objects = trees.o create_bst.o inorder_tree.o preorder_tree.o postorder_tree.o moriss-tree.o queue.c stack.o breadth_first.o
%.o : LIBFLAG = -ggdb -fPIC
%.o : CFLAG = -g
mytree : $(objects)
	gcc $(CFLAG) -g -o mytree $(objects) -lrt
cleanobj:
	rm *.o

