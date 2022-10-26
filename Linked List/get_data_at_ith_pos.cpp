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
/*
void printIthNode(Node *head , int i){
    int j=0;
    Node *temp=head;
    while(j<i){
        temp=temp->next;
        j++;
    }
    cout<<temp->data<<endl;
}*/

///////RECURSION WALA FUNCTION
void printIthNode(Node *head, int i)
{
    if (head==NULL){
        cout<<"";
    }
    if (i==0){
        cout<<head->data<<endl;
    }
    else{
        printIthNode(head->next, i-1);
    }
}
///////////////////////////////

int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head= takeInput();
        int i;
        cin>>i;
        printIthNode(head,i);
        
    }
    return 0;
}