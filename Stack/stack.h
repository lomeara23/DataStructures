#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<class T>
class stack
{
public:
    stack(); //Default constructor
    stack(int maxSize); //Overloaded constructor
    ~stack(); //Destructor
    void push(T data); //Add object to stack
    T pop(); //Remove object from stack and return it
    T peek(); //AKA top(), return top object without removing it
    int size(); //Return number of objects on stack
    bool isEmpty(); //Check if stack is empty
    bool isFull(); //Check if stack is full
    

private:
    T* arr;
    int mSize;
    int top;
};

#endif