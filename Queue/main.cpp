#include "Queue.h"

int main(int argc, char const *argv[])
{
    Queue *myQueue = new Queue(5);
    myQueue->insert('a');
    myQueue->insert('b');
    myQueue->insert('c');
    myQueue->insert('d');
    cout << "PEEK: " << myQueue->peek() << endl;
    cout << "SIZE: " << myQueue->size() << endl;
    return 0;
}
