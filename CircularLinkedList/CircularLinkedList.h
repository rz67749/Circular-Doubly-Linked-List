#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "ItemType.h"

struct NodeType
{
  ItemType data;
  NodeType *next;
};

class CircularLinkedList
{
 public:
  CircularLinkedList();
  ~CircularLinkedList();
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  int lengthIs() const;
  void print();
 private:
  int length;
  NodeType *head;

};

#endif