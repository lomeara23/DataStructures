#include "stack.h"

template <class T> stack<T>::stack(){
    mSize = 64;
    top = -1;
    arr = new char[mSize];
}
template <class T> stack<T>::stack(int maxSize){
    mSize = maxSize;
    top = -1;
    arr = new char[mSize];
}

template <class T> stack<T>::~stack(){
    delete[] arr;
}

template <class T> void stack<T>::push(T newData){
    if (isFull()) {
        throw runtime_error("stack is full");
    }
    else
        arr[++top] = newData;
}
template <class T> T stack<T>::pop(){
    if (isEmpty()){
        throw runtime_error("stack is empty");
    } else {
        return arr[top--];
    }
}

template <class T> T stack<T>::peek(){
    if (isEmpty()){
        throw runtime_error("stack is empty");
    } else {
        return arr[top];
    }}
template <class T> int stack<T>::size(){
    return (top + 1);
}
template <class T> bool stack<T>::isFull(){
    return (top == (mSize - 1));
}
template <class T> bool stack<T>::isEmpty(){
    return (top == -1);
}