#include <stack>
using namespace std;

void zigZagOrder(BinaryTreeNode<int>* root){
    if (root==NULL){
        return;
    }

    stack<BinaryTreeNode<int>*> stack1;
    stack<BinaryTreeNode<int>*> stack2;
    stack1.push(root);
    
    while (stack1.empty() && stack2.empty()){
        while (!stack1.empty()){
            BinaryTreeNode<int>* top=stack1.top();
            
            cout<<top->data<<" ";
            stack1.pop();
            
            if (top->left!=NULL){
                stack2.push(top->left);
            }
            
            if (top->right!=NULL){
                stack2.push(top->right);
            }
            
            if (stack1.empty()){
                cout<<endl;
            } 
        }
        
        //cout<<endl;
        
        while (!stack2.empty()){
            BinaryTreeNode<int>* top=stack2.top();
            cout<<top->data<<" ";
            stack2.pop();
            
            if (top->right!=NULL){
                stack1.push(top->right);
            }
            
            if (top->left!=NULL){
                stack1.push(top->left);
            } 
            
            if (stack2.empty()){
                cout<<endl;
            }
        }
        
    }
}