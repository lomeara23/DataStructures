#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// #include <iostream>
// using namespace std;

#include "ListNode.h"

class SingleLinkedList{
    protected:
        ListNode *front;
        ListNode *back;
        unsigned int size;

    public:
        SingleLinkedList();
        ~SingleLinkedList();

        void insertFront(int d);
        int removeFront();

        void insertBack(int d);
        int removeBack();

        int find(int value);
        int deleteAtPos(unsigned int pos);
        
        bool isEmpty();
        int getSize();

};

#endif