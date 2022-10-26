#include <iostream>
#include <queue>
#include <utility>
using namespace std;

template <typename T>
class BinaryTree{
    public:
    T data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTree(){
        delete left;
        delete right;
    }
};


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

/*
int height(BinaryTree<int> *root){
    if (root==NULL){
        return 0;
    }
    return 1+max(height(root->left) , height(root->right));
}

int diameter(BinaryTree<int> *root){
    if (root==NULL){
        return 0;
    }
    int option1 = height(root->left)+height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1 , max(option2 , option1));
}

//6 5 4 2 3 -1 -1 1 -1 7 8 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTree<int> *root=takeInputLevelWise();
    cout<<endl;
    cout<<"diameter is : "<<diameter(root)<<endl;
}
*/

pair<int,int> heightdiameter(BinaryTree<int> *root){
    if (root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
    }
    pair<int,int> leftAns = heightdiameter(root->left);
    pair<int,int> rightAns = heightdiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh , max(ld , rd));
    pair<int,int> final;
    final.first=height;
    final.second=diameter;
    return final;
}

int main(){
    BinaryTree<int> *root=takeInputLevelWise();
    cout<<endl;
    pair<int,int> p=heightdiameter(root);
    cout<<"height is : "<<p.first<<endl;
    cout<<"diameter is : "<<p.second<<endl;
}