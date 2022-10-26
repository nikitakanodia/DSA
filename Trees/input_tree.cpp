#include <vector>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode<T> *> children;
    TreeNode(T data){
        this->data = data;
    }
};

/*
void print_tree(TreeNode <int> * root){
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

TreeNode <int> * takeInputLevelWise(){
    int rootdata;
    cout<<"enter data : ";
    cin>>rootdata;
    TreeNode <int> * root = new TreeNode<int>(rootdata);
    queue <TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() !=0 ){
        TreeNode <int> * front = pendingnodes.front();
        pendingnodes.pop();
        int numchild;
        cout<<"enter number of children of "<< front->data << " : ";
        cin>>numchild;
        cout<<endl;
        for(int i=0 ; i< numchild ; i++){
            int childdata;
            cout<<"enter data of "<< i<< "th child of " << front->data << " : ";
            cin>>childdata;
            cout<<endl;
            TreeNode <int> * child = new TreeNode<int> (childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

// 6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0
int main(){
    TreeNode <int> * root= takeInputLevelWise();
    printLevelWise(root);
}