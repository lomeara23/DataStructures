#include "LinkedList.h"

LinkedList::LinkedList(){
    // Empty list
    front = NULL;
    back = NULL;
    size = 0;
}
LinkedList::~LinkedList(){
    while(!isEmpty()){
        removeFront();
    }
}

void LinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

void LinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    size++;
}

int LinkedList::removeFront(){
    ListNode *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    int data = temp->data;
    size--;
    delete temp;

    return data;
}

int LinkedList::removeBack(){
    ListNode *temp = back;

    if(back->prev == NULL){
        front = NULL;
    }
    else{
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    int data = temp->data;
    size--;
    delete temp;

    return data;
}

int LinkedList::find(int value){
    int pos = -1;
    ListNode *curr = front;

    while (curr != NULL)
    {
        ++pos;
        if(curr->data == value){
            break;
        }
        curr = curr->next;
    }
    if(curr == NULL){
        pos = -1;
    }
    return pos;
}

int LinkedList::removeNode(int value){
    if(isEmpty()){
        throw runtime_error("List is empty");
    }

    ListNode *curr = front;
    while(curr->data != value){
        curr = curr->next;
        if(curr == NULL){
            return -1;
        }
    }

    if(curr != front){
        curr->prev->next = curr->next;
        curr->prev = NULL;
    }
    else{
        curr->next = front;
    }
    if(curr != back){
        curr->next->prev = curr->prev;
        curr->next = NULL;
    }
    else {
        curr->prev = back;
    }
    int data = curr->data;
    --size;
    delete curr;

    return data;
}