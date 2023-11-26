#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template<class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T data);
        virtual ~TreeNode();

        T key;

        TreeNode<T> *left;
        TreeNode<T> *right;
        
};

template<class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}

template<class T>
TreeNode<T>::TreeNode(T key){
    left = NULL;
    right = NULL;
    this->key = key;
}

template<class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template<class T>
class BST{
    public:
        BST();
        virtual ~BST();

        void insert(T value);
        bool deleteNode(T k);
        bool contains(T value);
        bool isEmpty();

        TreeNode<T>* getSuccessor(TreeNode<T>* node);

        void printTree();
        void recPrint(TreeNode<T>* node);

        T* getMin();
        T* getMax(); 

        T* getRoot();

        private: 
        TreeNode<T> *root;
};

template<class T>
BST<T>::BST(){
    root = NULL;
}

template<class T>
BST<T>::~BST(){
    // research
}

template<class T>
void BST<T>::insert(T val){
    if (root == NULL) {
        root = new TreeNode<T>(val);
        return;
    }

    TreeNode<T> *parent = root;
    TreeNode<T> *current = root;

    while(current != NULL){
        parent = current;
        if(val < current->key){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if(val < parent->key){
        parent->left = new TreeNode<T>(val);
    } else {
        parent->right = new TreeNode<T>(val);
    }  
}


template<class T>
bool BST<T>::deleteNode(T k){
    cout << "Not yet implemented!" << endl;
    if(isEmpty()){
        return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(current->key != k){
        parent = current;
        if(k < current->key){
            current = current->left;
        }else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL){
            return false;
        }
    }
    // node to delete found

    // Leaf node, no children
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        } else if(isLeft){
            parent->left = NULL;
        } else{
            parent->right = NULL;
        }
    }

    // Node has left child
    else if(current->right == NULL){
        if(current = root){
            root = current->left;
        } else if(isLeft){
            parent->left = current->left;
        } else{
            parent->right = current->left;
        }

    }

    // Node has right child
    else if(current->left == NULL){
        if(current = root){
            root = current->right;
        } else if(isLeft){
            parent->left = current->right;
        } else{
            parent->right = current->right;
        }
    }

    // Node has two children
    else{
        TreeNode<T> *successor = getSuccessor(current);
        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
}

template<class T>
bool BST<T>::contains(T val){
    if(isEmpty()){
        return false;
    }
    TreeNode<T> *current = root;
    while(current->key != val && current != NULL){
        if(val < current->key){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if(current->key == val){
        return true;
    } else {
        return false;
    }
}

template<class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* node){
    TreeNode<T> *sp = node;
    TreeNode<T> *successor = node;
    TreeNode<T> *current = node->right;
    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    if(successor != right){
        sp->left = successor->right;
        successor->right = node->right;
    }
    return successor;
}

template<class T>
void BST<T>::printTree(){
    recPrint(root);
}

template<class T>
void BST<T>::recPrint(TreeNode<T>* node){
    cout << node->key << endl;
    if(node->left != NULL){
        recPrint(node->left);
    }
    if(node->right != NULL){
        recPrint(node->right);
    }
}

template<class T>
T* BST<T>::getMin(){
    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return &current->left;
}

template<class T>
T* BST<T>::getMax(){
    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return &current->right;
}

template<class T>
T* BST<T>::getRoot(){
    return root;
}

#endif