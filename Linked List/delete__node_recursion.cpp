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

Node *deleteNode(Node *head, int i){
    int j=0;
    if (head==NULL){
        return head;
    }
    if (i==0){
        return head->next;
    }
    Node *temp=deleteNode(head->next, i-1);
    head->next=temp;
    return head;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head= takeInput();
        int i;
        cout<<"enter position of element to be deleted : ";
        cin>>i;
        head=deleteNode(head, i);
        cout<<"updated list is : "<<endl;
        printList(head);
    }
    return 0;
}



