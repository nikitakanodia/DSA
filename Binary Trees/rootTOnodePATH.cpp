#include <iostream>
#include <vector>
#include <queue>
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

vector<int>* rootTOnodePATH(BinaryTree <int> *root , int k){
    if (root == NULL){
        return NULL;
    }
    if (root->data == k){
        vector<int> *rootTOnode = new vector<int>();
        rootTOnode->push_back(root->data);
        return rootTOnode;
    }
    vector<int> *leftpath = rootTOnodePATH(root->left , k);
    if (leftpath != NULL){
        leftpath->push_back(root->data);
        return leftpath;
    }
    vector<int> *rightpath = rootTOnodePATH(root->right , k);
    if (rightpath!=NULL){
        rightpath->push_back(root->data);
        return rightpath;
    }
    else{
        return NULL;
    }
}

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

int main(){
    BinaryTree<int>*root = takeInputLevelWise();
    int n;
    cout<<"enter element whose path is to be searched : ";
    cin>>n;
    vector<int> *final=rootTOnodePATH(root , n);
    for (int i=0 ; i<final->size() ; i++){
        cout<< final->at(i) <<" ";
    }
    cout<<endl;
}