#include <iostream>
using namespace std;

void print(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(int arr[] , int n){
    int i = 0;
    int j = n-1;
    while(i<j){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}


int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<<"original array : "<<endl;
    print(arr ,7);
    reverse(arr,7);
    cout<<"reversed array : "<<endl;
    print(arr , 7);
}