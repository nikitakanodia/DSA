#include<unordered_map>
#include <iostream>
#include <string>
using namespace std;
string uniqueChar(string str) {
    unordered_map<char , int> unique;
    string output;

    for(int i=0 ; i< str.length() ; i++){
        
        if (unique.count(str[i]) > 0 ){
            unique[str[i]]++;
            continue;
        }

        unique[str[i]]=1;
        output += str[i];
    }

    return output;
    
}
  
int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}

// Time Complexity : O(n)
// Auxillary Space : O(n)