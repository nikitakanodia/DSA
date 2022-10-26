#include <iostream>
using namespace std;
#include "Queue_using_array.h"

int main(){
    QueueUsingArray <int> s(5);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.front()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isEmpty()<<endl;
}