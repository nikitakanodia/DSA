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

class Pair{
    public:
        Node *head;
        Node *tail;
};


/*         WHY POINTER VARIABLE OF FORM PAIR IS NOT CREATED?
Pair *reverse(Node *head)
{
    if(head==NULL || head->next==NULL){
        Pair *ans;
        ans->head=head;
        ans->tail=head;
        return ans;
    }
    Pair *smallans=reverse(head->next);
    (smallans->tail)->next=head;
    head->next=NULL;
    Pair *ans;
    ans->head=smallans->head;
    ans->tail=head;
    return ans;
}

Node *reverse_better(Node *head){
    return reverse(head)->head ;
}
*/


Pair reverse(Node *head)
{
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallans=reverse(head->next);
    smallans.tail -> next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    return ans;
}

Node *reverse_better(Node *head){
    return reverse(head).head ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head= takeInput();
        Node *tail=reverse_better(head);
        cout<<"updated list is : "<<endl;
        printList(tail);
    }
    return 0;
}