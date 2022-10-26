#include <bits/stdc++.h>
using namespace std;
#include <climits>

int lcs(string s, string t){
    if (s.length()==0 || t.length()==0){
        return 0;
    }
    if (s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }
    int a = lcs( s.substr(1) , t);
    int b = lcs( s , t.substr(1));
    //c is redundant i.e. it will be automatically be taken care of in a & b
    // int c = lcs( s.substr(1) , t.substr(1));
    // return max(a,max(b,c));
    return max(a,b);
}


int main() {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
}