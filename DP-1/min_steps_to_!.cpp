#include <iostream>
#include <climits>
using namespace std;

int countMinStepsToOne(int n)
{
    if(n==1){
        return 0;
    }
    int x=INT_MAX;
    int y=INT_MAX;
    int z=INT_MAX;
    x = countMinStepsToOne(n-1);
    if (n%2==0){
        y = countMinStepsToOne(n/2);
    }
    if (n%3==0){
        z = countMinStepsToOne(n/3);
    }
    return min(x,min(y,z))+1 ;
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}