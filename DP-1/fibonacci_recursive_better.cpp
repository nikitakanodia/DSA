#include <iostream>
using namespace std;

int fibo_helper(int *arr , int n){
    if (n<=1){
        return n;
    }
    if (arr[n]!=-1){
        return arr[n];
    }
    int a = fibo_helper(arr,n-1);
    int b = fibo_helper(arr , n-2);
    arr[n]=a+b;
    return arr[n];
}

int fibo(int n){
    int *arr = new int[n+1];
    for(int i=0 ; i<=n ; i++){
        arr[i]=-1;
    }
    //DONT KNOW HOW DELETE WORKS
    // int *temp = arr;
    // delete []temp;
    return fibo_helper(arr , n);
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
}