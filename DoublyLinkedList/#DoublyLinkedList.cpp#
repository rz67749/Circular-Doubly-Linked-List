#include <iostream>
#include "ItemType.h"
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
    length = 0;
} //DoublyLinkedList Constructor

DoublyLinkedList::~DoublyLinkedList(){
    NodeType *tempNode = head;
    if (tempNode->next == NULL){
        delete tempNode;
    } else {
        while (tempNode != NULL){
            NodeType *newNode;
            newNode = tempNode;
            tempNode = tempNode->next;
            delete newNode;
        } //while
    } //else-if
} //DoublyLinkedList Destructor

int DoublyLinkedList::lengthIs() const{
    return length;
} //lengthIs

void DoublyLinkedList::insertItem(ItemType &item){
    NodeType *newNode;
    NodeType *location;
    NodeType *prevNode;
    bool moreToSearch, duplicate;
    
    //create new node
    newNode = new NodeType();
    newNode->data = item;

    if (head != NULL){ // checks that list isn't empty
        location = head;
        prevNode = NULL;
        moreToSearch = true;
        duplicate = false;
        // comparisons
        while (moreToSearch){
            switch (item.compareTo(location->data)){
            case LESS:
                moreToSearch = false;
                break;
            case GREATER:
                prevNode = location;
                location = location->next;
                moreToSearch = (location != NULL);
                break;
            case EQUAL: // avoids duplicates
                delete newNode; // prevents memory leak
                cout << "Item already exists!\n" << endl;
                moreToSearch = false;
                duplicate = true;
                break;
            } //switch
        } //while
        // special cases
        if (!duplicate && location == head){ //in case item is before first item in list
            newNode->next = head;
            newNode->back = NULL;
            head->back = newNode;
            head = newNode;
            length++;
        } else if (!duplicate && location == NULL){ //add to the end of the list
            prevNode->next = newNode;
            newNode->back = prevNode;
            newNode->next = NULL;
            length++;
        } else if (!duplicate){ //inserting in the middle of a list
            newNode->next = location;
            newNode->back = location->back;
            (location->back)->next = newNode;
            location->back = newNode;
            length++;
        } //else-if         
    } else { // in case list is empty 
        head = newNode;
        head->next = NULL;
        head->back = NULL;
        length++;
    } //else-if    
}//insertItem

void DoublyLinkedList::deleteItem(ItemType &item){
    bool moreToSearch, found;
    NodeType *location;
    //search for item
    if (head != NULL){ //checks that list isn't empty 
        location = head;
        moreToSearch = true;
        found = false;
        while (moreToSearch){
            switch(item.compareTo(location->data)){
            case EQUAL:
                moreToSearch = false;
                found = true;
                break;
            case GREATER:
                location = location->next;
                moreToSearch = (location != NULL);
                break;
            case LESS:
                moreToSearch = false;
                break;
            };//switch
        }//while
        
        if (found){ // delete
            if (head == location){ // if deleting from the front of the list
                if (location->next == NULL){ //if deleting only element in list 
                    head = NULL;
                    delete location;
                } else { // delete front node
                    head = location->next;
                    head->back = NULL;
                    delete location;
                }//else-if
            } else if (location->next == NULL){ // if deleting the last element
                location->back->next = NULL;
                delete location;
            } else { // delete from middle 
                location->back->next = location->next;
                location->next->back = location->back;
                delete location;
            }//else-if
            length--;
        } else { // if item not found
            cout << "Item not in list!\n" << endl;
        }//else-if
    } else { // if list is empty
        cout << "The list is empty\n" << endl;
    }    
}//deleteItem

void DoublyLinkedList::print(){
    NodeType *location;
    location = head;
    if (head == NULL){ // if list is empty 
        cout << "List Empty\n" << endl;
    } else {
        while(location != NULL){ // loop to print 
            cout << location->data.getValue() << " ";
            location = location->next;
        }
        cout << "\n\n";
    }
}//print

