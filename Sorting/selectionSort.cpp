#include <iostream>
using namespace std;

void selectionSort(int *arr , int n){
    for (int i=0 ; i<n-1 ; i++){
        int min = arr[i];
        int minindex = i;
        for(int j=i+1 ; j<n ; j++){
            if (arr[j]<min){
                minindex = j;
                min = arr[j];
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[]={3,5,2,4,1};
    selectionSort(arr,5);
    for(int i=0 ; i<5 ; i++){
        cout<<arr[i]<<" ";
    }
}