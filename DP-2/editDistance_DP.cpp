#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int editDistance(string s, string t , int **output) {
	int m = s.size();
	int n = t.size();
    if (s.size()<=0 || t.size()<=0){
        return max(m,n);
    }
    int ans;
    for(int i=0 ; i<=m ; i++){
        output[i][0] = i;
    }
    for(int j=1 ; j<=n ; j++){
        output[0][j] = j;
    }
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            if (s[0]==t[0]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                int x = 1+output[i-1][j]; //INSERT IN T
                int y = 1+output[i-1][j]; //DELETE FROM T
                int z = 1+output[i-1][j-1];//REPLACE IN T
                ans = min(x,min(y,z));
                output[i][j]=ans;
            }
        }
    }
    return output[m][n];
}

int editDistance(string s, string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i=0 ; i<=m ; i++){
        output[i]=new int[n+1];
    }
    return editDistance(s , t , output);
}


int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}