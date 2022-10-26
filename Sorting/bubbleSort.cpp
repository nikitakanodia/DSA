#include <iostream>
using namespace std;

void bubbleSort(int *arr , int n){
    for (int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[]={3,5,2,4,1};
    bubbleSort(arr,5);
    for(int i=0 ; i<5 ; i++){
        cout<<arr[i]<<" ";
    }
}