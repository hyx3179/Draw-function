objects = main.o svbmp.o

edp : $(objects)
	gcc -s -o drawfun $(objects) -lm

mian.o : mian.c
svbmp.o : svbmp.c

.PHONY : clean
clean :
	-rm drawfun $(objects) graph.bmp
