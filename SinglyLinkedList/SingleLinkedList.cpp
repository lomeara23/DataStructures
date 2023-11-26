#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(){
    front = NULL;
    size = 0;
}
SingleLinkedList::~SingleLinkedList(){}

void SingleLinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        back = node;
    } else {
        node->next = front;
    }
    front = node;
    size++;
}
int SingleLinkedList::removeFront(){
    if(isEmpty()){
        cerr << "list is empty" << endl;
        return -1;
    }

    int temp = front->data;
    ListNode *ft = front;

    front = front->next;
    ft->next = NULL;
    delete ft;

    size--;
    return temp;
}

void SingleLinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        front = node;
    } else {
        back->next = node;
    }
    back = node;
    size++;
}
int SingleLinkedList::removeBack(){
    ListNode *curr = front;
    ListNode *prev;
    while(curr != back){
        prev = curr;
        curr = curr->next;
    }
    back = prev;
    int d = curr->data;
    delete curr;
    return d;
}

int SingleLinkedList::find(int value){
    int pos = -1;
    ListNode *curr = front;
    while(curr->data != NULL){
        pos++;
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
int SingleLinkedList::deleteAtPos(unsigned int pos){
    int idx = 0;
    ListNode *curr = front;
    ListNode *prev;
    while(idx != pos){
        prev = curr;
        curr = curr->next;
        idx++;        
    }
    if(curr == front){
        front = front->next;
    }
    if(curr == back){
        back = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    int d = curr->data;
    delete curr;
    return d;
}

bool SingleLinkedList::isEmpty(){
    return(size == 0);
}
int SingleLinkedList::getSize(){
    return size;
}