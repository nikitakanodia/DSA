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

Node *merge(Node *head1, Node *head2){
    Node *fhead=NULL ; 
    Node *ftail=NULL;
    Node *temp1=head1;
    Node *temp2=head2;
    if (head1==NULL){
        return head2;
    }
    else if(head2==NULL) {
        return head1;
    }
    while (temp1!=NULL && temp2!=NULL){
        if (temp1->data < temp2->data){
            if (fhead==NULL){
                fhead=temp1;
                ftail=temp1;
            }
            else {
                ftail->next=temp1;
                ftail=temp1;
            }
            temp1=temp1->next;
        }
        else if (temp1->data >= temp2->data){
            if (fhead==NULL){
                fhead=temp2;
                ftail=temp2;
            }
            else{
                ftail->next=temp2;
                ftail=temp2;
            }
            temp2=temp2->next;
        } 
    }
    while (temp2==NULL){
        ftail->next=temp1;
    }
    if (temp1==NULL){
        ftail->next=temp2;
    } 
    return fhead;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head1= takeInput();
        Node *head2= takeInput();
        Node *fhead=merge(head1, head2);
        cout<<"updated list is : "<<endl;
        printList(fhead);
    }
    return 0;
}



