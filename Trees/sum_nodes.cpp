#include "class_input_print.cpp"
#include <iostream>
using namespace std;

int sumNodes(TreeNode <int> * root){
    if (root==NULL){
        return -1;
    }
    int sum=root->data;
    for(int i=0 ; i<root->children.size() ; i++){
        sum+=sumNodes(root->children[i]);
    }
    return sum;
}

// 6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0
int main(){
    TreeNode <int> * root= takeInputLevelWise();
    cout<<"sum of all nodes are : " << sumNodes(root);
}