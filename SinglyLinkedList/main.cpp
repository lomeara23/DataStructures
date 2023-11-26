#include "SingleLinkedList.h"

int main(int argc, char const *argv[])
{
    SingleLinkedList *sll = new SingleLinkedList();

    sll->insertFront(1);
    sll->insertFront(5);
    sll->insertFront(6);
    sll->insertFront(19);
    sll->insertFront(3);
    sll->insertFront(1);


    cout << sll->deleteAtPos(2) << endl;

    // while(!sll->isEmpty()){
    //     cout << sll->removeFront() << endl;
    // }
    return 0;
}
