#include "queue1.h"
#include <climits>
#include <iostream>
using namespace std;


int main() {
    PriorityQueue pq;

    int choice;
    cout<<"Enter choice : ";
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cout<<"Enter element : ";
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout <<"min : "<< pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout <<"removed min element : "<< pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout <<"size : "<< pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout <<"isEmpty : "<< (pq.isEmpty() ? "true\n" : "false\n");
                break;
            default:
                return 0;
        }
        cout<<"Enter choice : ";
        cin >> choice;
    }
}