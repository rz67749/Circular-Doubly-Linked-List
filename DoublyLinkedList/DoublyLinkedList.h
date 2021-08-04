#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "ItemType.h"
#include "DoublyLinkedList.h"

struct NodeType
{
    ItemType data;
    NodeType *next;
    NodeType *back;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int lengthIs() const;
    void insertItem(ItemType &item);
    void deleteItem(ItemType &item);
    void print();
    
private:
    NodeType *head;
    int length;
};
#endif
