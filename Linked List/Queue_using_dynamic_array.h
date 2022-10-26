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
            T *newdata= new T[2*capacity];
            int j=0;
            for(int i=firstIndex; i<capacity ; i++){
                newdata[j]=data[i];
                j++;
            }
            for(int i=0; i<firstIndex ; i++){
                newdata[j]=data[i];
                j++;
            }
            delete []data;
            data=newdata;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
            return ;
        }
        // if (nextIndex!=capacity){
        //     data[nextIndex]=element;
        //     nextIndex++;
        //     if(firstIndex==-1){
        //         firstIndex=0;
        //     }
        // }
        // else{
        //     nextIndex=0;
        //     data[nextIndex]=element;
        //     nextIndex++;
        //     if (firstIndex==-1){
        //         firstIndex=0; 
        //     }
        // }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if (firstIndex==-1){
            firstIndex=0; 
        }
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