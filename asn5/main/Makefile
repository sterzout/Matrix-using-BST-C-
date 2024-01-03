export: main
main: main.o datatype bstree matrix
	gcc -o main main.o ../datatype/datatype.o \
		../bstree/bstree.o\
		../matrix/matrix.o
main.o: main.c ../Include/*.h
	gcc -I../Include -c main.c
datatype:
	(cd ../datatype; make export)
bstree:
	(cd ../bstree; make export)
matrix:
	(cd ../matrix; make export)
print:
	lpr main.c
printall:
	lpr main.c
	(cd ../datatype; make print) (cd ../bstree; make print)(cd ../matrix; make print)
clean:
	rm -f *.o main core
cleanall:
	rm -f *.o main core
	(cd ../datatype; make clean) (cd ../bstree; make clean) (cd ../matrix; make clean) 

