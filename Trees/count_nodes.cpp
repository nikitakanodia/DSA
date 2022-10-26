#include "class_input_print.cpp"
#include <iostream>
using namespace std;

/*
int numNodes(TreeNode <int> * root)
{
    if (root==NULL){
        return -1;
    }
    queue <TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    int count=1;
    while(pendingnodes.size()!=0){
        TreeNode<int> * front = pendingnodes.front();
        pendingnodes.pop();
        for(int i=0 ; i<front->children.size() ; i++){
            count++;
            pendingnodes.push(front->children[i]);
        }
    }
    return count;
}
*/

int numNodes(TreeNode <int> * root){
    if (root==NULL){
        return -1;
    }
    int count=1;
    for(int i=0 ; i<root->children.size() ; i++){
        count+=numNodes(root->children[i]);
    }
    return count;
}

// 6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0
int main(){
    TreeNode <int> * root= takeInputLevelWise();
    cout<<"total nodes are : " << numNodes(root);
}