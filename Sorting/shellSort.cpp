#include <iostream>
using namespace std;

void shellSort(int *arr , int n){
    for (int interval=n/2 ; interval>0 ; interval/=2){

        for(int i=interval ; i<n ; i++){
            int temp = arr[i];
            int j;

            for(j=i ; j>=interval && arr[j-interval]>temp ; j = j-interval){
                arr[j] = arr[j-interval];
            }


            arr[j] = temp;

        }

    }
}

int main(){
    int arr[]={3,5,2,4,1};
    shellSort(arr,5);
    for(int i=0 ; i<5 ; i++){
        cout<<arr[i]<<" ";
    }
}