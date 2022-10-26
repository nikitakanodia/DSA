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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}

