#include "class.h"
#include "print.cpp"
#include <queue>
#include <iostream>
using namespace std;

BinaryTree<int> * takeInputLevelWise(){
    int rootdata;
    cout<<"Enter root data : ";
    cin>>rootdata;
    if (rootdata==-1){
        return NULL;
    }
    BinaryTree<int> *root=new BinaryTree<int> (rootdata);
    queue<BinaryTree<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size()!=0){
        BinaryTree<int> *front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter left child of "<<front->data<<" : ";
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata!=-1){
            BinaryTree<int> *leftchild=new BinaryTree<int>(leftchilddata);
            front->left=leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<"Enter right child of "<<front->data<<" : ";
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata!=-1){
            BinaryTree<int> *rightchild=new BinaryTree<int>(rightchilddata);
            front->right=rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}


// int main(){
//     BinaryTree<int> *root =takeInputLevelWise();
//     printBinaryTree(root);
// }
