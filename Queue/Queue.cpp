#include "Queue.h"

Queue::Queue(){
    mSize = 128;
    front = 0;
    back = 0;
    myQueue = new char[mSize];    
}
Queue::Queue(int maxSize){
    mSize = maxSize;
    front = 0;
    back = 0;
    myQueue = new char[mSize];
}
Queue::~Queue(){
    delete[] myQueue;
}

void Queue::insert(char data){
    myQueue[back++] = data;

}
char Queue::remove(){
    return myQueue[front++];
}

char Queue::peek(){
    return myQueue[front];
}
bool Queue::isFull(){
    return (numElem == mSize);
}
bool Queue::isEmpty(){
    return (numElem == 0);
}
unsigned int Queue::size(){
    return numElem;
}