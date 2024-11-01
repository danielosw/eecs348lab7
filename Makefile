default: main.o
	gcc -o main main.o
main.o: main.cpp
	gcc -c main.cpp
clean:
	rm *.o
