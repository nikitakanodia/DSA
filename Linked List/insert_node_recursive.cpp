//#include <class_node.hpp>
//#include <take_input_in_linked_list.cpp>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while (data!=-1){
        Node *newnode= new Node(data);
        if (head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void printList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node *insertNode(Node *head, int i, int data){
    int j=0;
    if (head==NULL && i==0){
        Node *new_node = new Node(data);
        new_node->next=NULL;
        return new_node;
    }
    if (head==NULL && i>0){
        return head;
    }
    if (i==0){
        Node *new_node = new Node(data);
        new_node->next=head;
        return new_node;
    }
    Node *temp=insertNode(head->next, i-1, data); 
    head->next=temp;
    return head;
}


int main(){
    int t;
    cin>>t;
    while(t>=0){
        Node *head= takeInput();
        int i;
        cout<<"enter position where element is to be inserted : ";
        cin>>i;
        int data;
        cout<<"enter value of element to be inserted : ";
        cin>>data;
        head=insertNode(head, i, data);
        cout<<"updated list is : "<<endl;
        printList(head);
        t--;
    }
    return 0;
}



