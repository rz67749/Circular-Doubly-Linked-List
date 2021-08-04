#include "CircularLinkedList.h"
#include "ItemType.h"
#include <iostream>
                                                                                      
using namespace std;

CircularLinkedList::CircularLinkedList()
{
  length = 0;
  head = NULL;

}//CircularLinkedList Constructor
CircularLinkedList::~CircularLinkedList()
{
  NodeType *tempNode = head;
  if(tempNode->next == NULL)
  {
    delete tempNode;
  }//if
  else {
    while(tempNode != NULL)
    {
      NodeType *newNode;
      newNode = tempNode;
      tempNode = tempNode->next;
      delete newNode;
    }//while
  }//else
  
}//CircularLinkedList Destructor
void CircularLinkedList::insertItem(ItemType &item)
{
  NodeType *newNode;
  NodeType *prevNode;
  NodeType *location;
  bool moreToSearch;
  bool itemEqual = false;
  //node to insert
  newNode = new NodeType();
  newNode->data = item;
 
  //if list is not empty
  if(head != NULL)
  {
    location = head->next;
    prevNode = head;
    moreToSearch = true;
    //while not at end of list
    while(moreToSearch)
    {
      
        switch(item.compareTo(location->data)) {
        case LESS:
            moreToSearch = false;
            break;
        case GREATER:
            prevNode = location;
            location = location->next;
            moreToSearch = (location != head->next);
            break;
        case EQUAL:
            delete newNode; // delete node to prevent memory leak
            cout << "Item already exists!\n" << endl;
            itemEqual = true;
            moreToSearch = false;
            break;
        }//switch
    }//while
    //checks for duplicate
    if(!itemEqual)
    {  
      newNode->next = prevNode->next;
      prevNode->next = newNode;

      //if last node in list, reassign head
      if(item.compareTo(head->data) == GREATER)
      {
	head = newNode;
      }//if
      length++;
    }//if
  }//if
  else {
    head = newNode;
    newNode->next = newNode;
    length++;
  }//else
  
}//insertItem
void CircularLinkedList::deleteItem(ItemType &item)
{
  NodeType *location;
  NodeType *prevNode;
  bool found;
  bool moreToSearch;

  moreToSearch = true;
  found = false;
  //checks if list is empty
  if(head != NULL)
  {
    location = head->next;
    prevNode = head;
    //while not end of list and item has not been found
    while(moreToSearch && !found)
    {
      switch(item.compareTo(location->data))
      {
      case LESS:
      case GREATER:
	prevNode = location;
	location = location->next;
	//checks end of list
	moreToSearch = (location != head->next);
	break;
      case EQUAL:
	found = true;
	break;
      }//switch
    }//while
  }//if
  //if item to delete is in list
  if(found)
  {
    //only item in list
    if(prevNode == location)
    {
      head = NULL;
    }//if
    else {
      prevNode->next = location->next;
      //insert in end of list
      if(location == head)
      {
	head = prevNode;
      }//if
    }//else
    delete location;
    length--;
  }//if
  else {
    cout << "Item not in list!\n" << endl;
  }//else
}//deleteItem
int CircularLinkedList::lengthIs() const
{
  return length;
  
}//lengthIs
void CircularLinkedList::print()
{
  NodeType* tempLocation;
  //checks if list is empty
  if(head != NULL)
  {
    //prints first element then goes into while loop
    //first element printed outside of loop due to while terminating statement
    tempLocation = head->next;
    cout << tempLocation->data.getValue() << " ";
    tempLocation = tempLocation->next;
    while(tempLocation != head->next)
    {
      cout << tempLocation->data.getValue() << " ";
      tempLocation = tempLocation->next;
    }//while
    cout << endl;
  }//if
  else {
    cout << "List Empty\n" << endl;
  }//else
  cout << endl;
}//print
