#include "stack.h"

int main(int argc, char const *argv[])
{
    stack<int> *myStack = new stack<int>();
    try{
        myStack->push(1);
        myStack->push(2);
        myStack->push(3);
        myStack->push(4);

        cout << "Peek: " << myStack->peek() << endl;
        cout << "Pop: " << myStack->pop() << endl;
        cout << "Peek: " << myStack->peek() << endl;

        while(!myStack->isFull()){
            myStack->push('n');
        }
        cout << "Size: " << myStack->size() << endl;
        myStack->push('n');
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    delete myStack;
    return 0;
}
