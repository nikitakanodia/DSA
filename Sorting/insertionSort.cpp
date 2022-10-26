
#include <bits/stdc++.h>
using namespace std;


void insertionSort(int *arr , int n){
    int i,j,key;
    for (int i=1; i<n ; i++){
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
    int N;
    cout<<"enter number of elements in the array : ";
    cin>>N;
    int *arr = new int (N);
    for(int i=0 ; i< N ; i++){
        int element;
        cout<<"enter "<<i<<" element : ";
        cin>>element;
        arr[i]=element;
    }
	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}