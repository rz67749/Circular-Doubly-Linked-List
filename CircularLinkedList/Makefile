GPP = g++
CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors

main: Main.cpp CircularLinkedList.o ItemType.o
	$(GPP) $(CFLAGS) -o main Main.cpp CircularLinkedList.o ItemType.o

ItemType.o: ItemType.cpp ItemType.h
	$(GPP) $(CFLAGS) -c ItemType.cpp

CircularLinkedList.o: CircularLinkedList.cpp CircularLinkedList.h ItemType.h
	$(GPP) $(CFLAGS) -c CircularLinkedList.cpp


clean:
	rm -rf main
	rm -rf *.o
