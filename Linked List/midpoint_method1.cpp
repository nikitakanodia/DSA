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
void printIthNode(Node *head , int i){
    int j=0;
    Node *temp=head;
    while(j<i){
        temp=temp->next;
        j++;
    }
    cout<<temp->data<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head= takeInput();
        int len=length(head);
        printIthNode(head, (len-1)/2);
    }
    return 0;
}



