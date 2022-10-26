/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include <climits>
using namespace std;


class BST {
    // Define the data member
    
   public:
    BinaryTreeNode<int> *root;
    
    BST(){
        root=NULL;
    }
    
    ~BST(){
        delete root;
    }
    public:
    bool searchHelper(int data , BinaryTreeNode<int> *node ){
        if (node==NULL){
            return 0;
        }
        if (node->data == data){
            return 1;
        }
        else if (node->data > data){
            return searchHelper(node->left);
        }
        else{
            return searchHelper(node->right);
        }
    }
    private:
    BinaryTreeNode<int> * insertHelper( int data , BinaryTreeNode<int> *node ){
        if (node==NULL){
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int> (data);
            return newnode;
        }
        if (node->data >=data){
            node->left=insertHelper(data , node->left);
        }
        else{
            node->right=insertHelper(data , node->right);
        }
        return node;
    }
    
    // int minimum(BinaryTreeNode<int> *node){
    //     if(node==NULL){
    //         return INT_MAX;
    //     }
    //     return min(node->data , min(minimum(node->right) , minimum(node->left)) );
         
    // }
    // int maximum(BinaryTreeNode<int> *node){
    //     if(node==NULL){
    //         return INT_MIN;
    //     }
    //     return max(node->data , max(maximum(node->right) , maximum(node->left)) );
    }
    
    BinaryTreeNode<int> * removeHelper( int data, BinaryTreeNode<int> *node){
        if (node==NULL){
            return NULL;
        }
        if (node->data > data){
            node->left=removeHelper(data , node->left);
            return node;
        }
        else if(node->data < data){
            node->right = removeHelper(data, node->right);
            return node;
        }
        else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            if(node->left!=NULL && node->right==NULL){
                BinaryTreeNode<int> *temp= node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            if( node->left==NULL && node->right!=NULL){
                BinaryTreeNode<int> *temp = node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            if (node->left!=NULL && node->right!=NULL){
                // if (node->data > data){
                //     node->data = maximum(node->left);
                // 	BinaryTreeNode<int> *newnode = removeHelper(node->data , node->left);
                // }
                // if (node->data < data){
                //     node->data = minimum(node->right);
                // 	BinaryTreeNode<int> *newnode = removeHelper(node->data , node->right);
                // }
                BinaryTreeNode<int> *minnode= node->right;
                while(minnode->left!=NULL){
                    minnode = minnode->left;
                }
                int mindata = minnode->data;
                node->data = mindata;
                node->right = removeHelper(mindata , node->right );
                return node;
            }
        }
    }
    
    public:
// 	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) {
        this->root=removeHelper(data, this->root);
        return;
    }

//     void print() { 
//         // Implement the print() function
//     }

    void insert(int data) { 
        this->root=insertHelper(data, this->root);
        return;
    }
    
    bool search(int data) {
		return searchHelper(data , root); 
    }
};





















