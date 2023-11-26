#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <exception>

using namespace std;

class Queue{
    public:
        Queue();
        Queue(int maxSize);
        ~Queue();

        //Core functions
        void insert(char data);
        char remove();

        //Auxiliary functions
        char peek();
        bool isFull();
        bool isEmpty();
        unsigned int size();
        void printArray();

    private:
        int mSize;
        int front;
        int back;
        unsigned int numElem = back - front;
        char *myQueue;
        
};

#endif
