#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


class Queue{
    Node *head;
    Node *tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return (size==0);
    }

    int front(){
        if (isEmpty()){
            return -1;
        }
        return head->data;
    }
    
    
    int dequeue(){
        if (isEmpty()){
            return -1;
        }
        int temp=head->data;
        Node *newnode=head;
        head=head->next;
        if (head==NULL){
            tail=NULL;
        }
        delete newnode;
        size--;
        return temp;
    }
    
    void enqueue(int element){
        Node *newnode= new Node(element);
        if (head==NULL){
            head=newnode;
            tail=newnode;
            size++;
            return;
        }
    	tail->next=newnode;
    	tail=tail->next;
    	size++;
    }
    
};


int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}