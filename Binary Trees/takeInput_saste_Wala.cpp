#include "class.h"
#include "print.cpp"
#include <iostream>
using namespace std;

BinaryTree<int>* takeInput(){
    int rootdata;
    cout << "enter data : ";
    cin>>rootdata;

    if (rootdata==-1){
        return NULL;
    }
    
    BinaryTree<int> *root=new BinaryTree<int>(rootdata);
    BinaryTree<int> *leftdata=takeInput();
    BinaryTree<int> *rightdata=takeInput();
    root->left=leftdata;
    root->right=rightdata;
}

int main(){
    BinaryTree<int> *root=takeInput();
    printBinaryTree(root);
}