#include "takeInputLevelWise.cpp"
#include "class.h"
#include <iostream>
#include <queue>
using namespace std;

void printLevelWise(BinaryTree<int>* root){
    if (root==NULL){
        return;
    }
    queue<BinaryTree<int>*> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size()!=0){
        BinaryTree<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<":";
        if (front->left != NULL){
            cout<<"L:"<<front->left->data<<",";
            pendingnodes.push(front->left);
        }
        else{
            cout<<"L:-1,";
        }
        if (front->right != NULL){
            cout<<"R:"<<front->right->data;
            pendingnodes.push(front->right);
        }
        else{
            cout<<"R:-1";
        }
        cout<<endl;
    }
}

int main(){
    BinaryTree<int>* root=takeInputLevelWise();
    printBinaryTree(root);
}

