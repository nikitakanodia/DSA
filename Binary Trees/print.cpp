#include "class.h"
#include <iostream>
using namespace std;

void printBinaryTree(BinaryTree<int> *root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left !=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right !=NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}


// int main(){
//     BinaryTree<int> *root=new BinaryTree<int>(1);
//     BinaryTree<int> *node1=new BinaryTree<int>(2);
//     BinaryTree<int> *node2=new BinaryTree<int>(3);   
//     root->left=node1;
//     root->right=node2;
//     printBinaryTree(root);
// }
