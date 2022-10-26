#include <iostream>
using namespace std;

int binarySearch(int arr[] , int n , int start , int end){
    while (start<=end){
        int mid = (start+end)/2;
        if (arr[mid]==n){
            return mid;
        }
        else if (arr[mid] < n){
            binarySearch(arr , n , mid+1 , end);
        }
        else{
            binarySearch(arr , n , start , mid-1);
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n;
    cout<<"element to be searched : ";
    cin>>n;
    cout<<endl;
    int a = binarySearch(arr , n , 0 , 9);
    if (a==-1){
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"element is at index "<<a<<endl;
    }
}