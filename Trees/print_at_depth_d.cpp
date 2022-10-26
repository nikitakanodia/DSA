#include "class_input_print.cpp"
#include <iostream>
using namespace std;

int getHeight(TreeNode <int> * root){
    if (root==NULL){
        return 0;
    }
    int height=1;
    for(int i=0 ; i<root->children.size() ; i++){
        int m=getHeight(root->children[i]);
        if (m>=height){
            height=1+m;
        }
    }
    return height;
}

void printAtDepthD(TreeNode <int> *root , int d){
    if (root==NULL){
        return;
    }
    if (d==0){
        cout<<root->data<< " ";
    }
    for(int i=0 ; i<root->children.size(); i++){
        printAtDepthD(root->children[i], d-1);
    }
}

// 6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0
int main(){
    TreeNode <int> *root=takeInputLevelWise();
    int d;
    cout<<"Enter depth at which nodes are to be found : ";
    cin>>d;
    int h=getHeight(root);
    if (d>=h){
        cout<<"\nNo Nodes exist at "<<d<<" depth"<<endl;
    }
    printAtDepthD(root,d);
}