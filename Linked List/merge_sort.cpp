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

Node * midPoint(Node *head){
    if(head==NULL){
        cout<<"";
    }
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL && fast->next->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

/* ///THIS IS GENERATING TIME COPLEXITY PROBLEM, DONT KNOW WHY? ///
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
*/
Node* merge(Node *head1, Node *head2) {
	if(head1 == NULL) {
		return head2;
	}
	if(head2 == NULL) {
		return head1;
	}
	Node *head = NULL, *tail = NULL;
	if(head1 -> data < head2 -> data) {
		head = head1;
		tail = head1;
		head1 = head1 -> next;
	}
	else {
		head = head2;
		tail = head2;
		head2 = head2 -> next;
	}

	while(head1 != NULL && head2 != NULL) {
		if(head1 -> data < head2 -> data) {
			tail -> next = head1;
			tail = head1;
			head1 = head1 -> next;
		}
		else {
			tail -> next = head2;
			tail = head2;
			head2 = head2 -> next;
		}
	}
	if(head1 != NULL) {
		tail -> next = head1;
	}
	if(head2 != NULL) {
		tail -> next = head2;
	}
	return head;
}


Node *mergeSort(Node *head1){
    if (head1==NULL || head1->next==NULL){
        return head1;
    }
    Node *mid=midPoint(head1);
    Node *head2=mid->next;
    mid->next=NULL;
    Node *new1=mergeSort(head1);
    Node *new2=mergeSort(head2);
    Node *fhead=merge(new1,new2);
    return fhead;
}

/*  //THIS IS ALSO CORRECT// 

Node *mergeSort(Node *head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    Node *mid=midPoint(head);
    Node *half1=head;
    Node *half2=mid->next;
    mid->next=NULL;
    half1=mergeSort(half1);
    half2=mergeSort(half2);
    Node *fhead=merge(half1,half2);
    return fhead;
}*/

int main(){
    int t;
    cin>>t;
    while(t--){
        Node *head= takeInput();
        head=mergeSort(head);
        cout<<"updated list is : "<<endl;
        printList(head);
    }
    return 0;
}