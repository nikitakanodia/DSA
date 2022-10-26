#include <iostream>
using namespace std;

class Sum
{
public:
    int a, b;
    Sum(int num1, int num2)
    { // parameterized constructor
        cout << "Constructor at	work" << endl;
        a = num1;
        b = num2;
    }
    ~Sum()
    { // destructor
        cout << "Destructor	at	work" << endl;
    }
    int getSum()
    {
        return a + b;
    }
};
int main()
{
    Sum obj(4, 6);
    cout<<"obj.a : "<<obj.a<<endl;
    cout<<"obj.b : "<<obj.b<<endl;

}