#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *evenAfterOdd(Node *head){
    Node *oddh=NULL, *oddt=NULL, *evenh=NULL, *event=NULL;
    if (head==NULL || head->next==NULL){
        return head;
    }
    while (head!=NULL){
        if (head->data %2 !=0){
            if (oddh==NULL){
                oddh=head;
                oddt=head;
            }
            else{
                oddt->next=head;
                oddt=oddt->next;
            }
        }
        else {
            if (evenh==NULL){
                evenh=head;
                event=head;
            }
            else{
                event->next=head;
                event=event->next;
            }
        }
        head=head->next;
    }
    if (oddh==NULL){
        event->next=NULL;
        return evenh;
    }
    if (evenh==NULL){
        oddt->next=NULL;
        return oddh;
    }
    else{
        event->next=NULL;
        oddt->next=evenh;
        return oddh;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}