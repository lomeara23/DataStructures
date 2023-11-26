#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

class LinkedList{
    private:
        ListNode *front;
        ListNode *back;
        unsigned int size;

    public:
        LinkedList();
        ~LinkedList();

        void insertFront(int d);
        void insertBack(int d);
        int removeFront();
        int removeBack();
        int removeNode(int val);
        int find(int val);
        bool isEmpty();
        unsigned int getSize();
        void printList(bool isPrintLink); // Not a part of standar implementation
};

#endif