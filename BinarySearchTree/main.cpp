#include "bst.h"

int main(int argc, char const *argv[])
{
    BST<int> *tree = new BST<int>();
    tree->insert(5);
    tree->insert(3);
    tree->insert(6);
    tree->insert(4);

    tree->printTree();
    return 0;
}
