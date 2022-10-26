#include <vector>
#include <iostream>
#include "treenode.h"
#include <queue>
using namespace std;

/*
void print_tree(treenode <int> * root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0 ; i<root->children.size() ; i++){
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i=0 ; i<root->children.size() ; i++){
        print_tree(root->children[i]);
    }
}
*/

void printLevelWise(TreeNode <int> * root)
{
    if (root==NULL){
        return;
    }
    queue <TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        TreeNode<int> * front = pendingnodes.front();
        cout<<front->data<<":";
        pendingnodes.pop();
        for(int i=0 ; i<front->children.size() ; i++){
            cout<<front->children[i]->data;
            if (i!=front->children.size()-1){
                cout<<",";
            }
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }
}


// 6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0
int main(){
    TreeNode <int> * root = new TreeNode<int> (1);
    TreeNode <int> * child1 = new TreeNode<int> (2);
    TreeNode <int> * child2 = new TreeNode<int> (3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    //print_tree(root);
    printLevelWise(root);
}