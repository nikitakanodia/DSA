#include <bits/stdc++.h>
using namespace std;
#include <climits>

int lcs(string s, string t , int **output){
    int m = s.size();
    int n = t.size();
    if (s.length()==0 || t.length()==0){
        return 0;
    }
    if (output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    if (s[0]==t[0]){
        ans = 1+lcs(s.substr(1) , t.substr(1) , output);
    }
    else{
        int a = lcs( s.substr(1) , t , output);
        int b = lcs( s , t.substr(1) , output);
        //c is redundant i.e. it will be automatically be taken care of in a & b
        // int c = lcs( s.substr(1) , t.substr(1) , output);
        // return max(a,max(b,c));
        ans = max(a,b);
    }
    output[m][n]=ans;
    return ans;
}

int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i=0 ; i<=m ; i++){
        output[i] = new int[n+1];
        for(int j=0 ; j<=n ; j++){
            output[i][j]=-1;
        }
    }
    return lcs(s,t,output);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
}