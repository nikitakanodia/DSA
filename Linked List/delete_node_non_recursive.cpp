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

int length(Node *head){
    if (head==NULL){
        return 0;
    }
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
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
    Node *temp=head;
    while(temp!=NULL && j<i-1){
        temp=temp->next;
        j++;
    }
    if (temp==NULL || temp->next==NULL){
        return head;
    }
    Node *a = temp->next;
    temp->next=a->next;
    return head;
}


int main(){
    int t;
    cin>>t;
    while(t>=0){
        Node *head= takeInput();
        int i;
        cout<<"enter position of element to be deleted : ";
        cin>>i;
        head=deleteNode(head, i);
        printList(head);
        t--;
    }
    return 0;
}



