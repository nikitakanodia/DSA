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


Node *reverseLinkedList(Node *head)
{
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *nextnode=head->next;
    Node *current=head;
    current->next=NULL;
    while (nextnode!=NULL){
        Node *temp=nextnode;
        nextnode=nextnode->next;
        temp->next=current;
        current=temp;;
    }
    return current;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head= takeInput();
        Node *tail=reverseLinkedList(head);
        cout<<"updated list is : "<<endl;
        printList(tail);
    }
    return 0;
}