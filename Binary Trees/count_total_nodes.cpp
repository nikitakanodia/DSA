#include "takeInputLevelWise.cpp"
#include "class.h"
#include <iostream>
using namespace std;

int numNodes(BinaryTree<int> *root){
    if (root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}
    
int main(){
    BinaryTree<int> *root =takeInputLevelWise();
    cout<<"total number of nodes in given tree is : "<<numNodes(root);
}
