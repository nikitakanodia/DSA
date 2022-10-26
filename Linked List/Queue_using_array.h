#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

    QueueUsingArray(int totalsize){
        data=new T[totalsize];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=totalsize;
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return (size==0);
    }

    void enqueue(T element){
        if (size==capacity){
            cout<<"queue is full"<<endl;
            return ;
        }
        if (nextIndex!=capacity){
            data[nextIndex]=element;
            nextIndex++;
            if(firstIndex==-1){
                firstIndex=0;
            }
        }
        else{
            nextIndex=0;
            data[nextIndex]=element;
            nextIndex++;
            if (firstIndex==-1){
                firstIndex=0; 
            }
        }
        // data[nextIndex]=element;
        // nextIndex=(nextIndex+1)%capacity;
        // if (firstIndex==-1){
        //     firstIndex=0; 
        // }
        size++;
    }

    T dequeue(){
        if ( isEmpty() ){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        int first=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;;
        size--; 
        if (size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return first;
    }

    T front(){
        if ( isEmpty() ){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    
};