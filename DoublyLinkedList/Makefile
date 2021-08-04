GPP = g++
CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors

main: Main.cpp DoublyLinkedList.o ItemType.o
	$(GPP) $(CFLAGS) -o main Main.cpp DoublyLinkedList.o ItemType.o

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h ItemType.h
	$(GPP) $(CFLAGS) -c DoublyLinkedList.cpp

ItemType.o: ItemType.cpp ItemType.h
	$(GPP) $(CFLAGS) -c ItemType.cpp


clean:
	rm -rf main
	rm -rf *.o
