#include <bits/stdc++.h>
using namespace std;
#include <climits>

int lcs(string s, string t , int **output){
    int m = s.size();
    int n = t.size();
    for(int i=0; i<=m ; i++){
        output[0][i] = 0;
    }
    for(int j=1 ; j<=n ; j++){
        output[j][0] = 0;
    }
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            if (s[i]==t[j]){
                output[i][j] = output[i-1][j-1] + 1;
            }
            else{
                int a = output[i-1][j-1];
                int b = output[i][j-1];
                int c = output[i-1][j];
                output[i][j] = max(a,max(b,c));
            }
        }
    }
    return output[m][n];
}

int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i=0 ; i<=m ; i++){
        output[i] = new int[n+1];
    }
    return lcs(s,t,output);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
}