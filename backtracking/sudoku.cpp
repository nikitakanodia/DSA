#include <bits/stdc++.h>
using namespace std;

#define n 9

bool isempty(int grid[n][n] ,int &row , int &col){
    for(int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool ispossibleROW(int grid[n][n] , int row , int num){
    for(int i=0 ; i<n ; i++){
        if (grid[row][i]==num){
            return false;
        }
    }
    return true;
}

bool ispossibleCOLUMN(int grid[n][n] , int col , int num){
    for(int i=0 ; i<n ; i++){
        if (grid[i][col]==num){
            return false;
        }
    }
    return true;   
}

bool ispossibleBOX(int grid[n][n] , int row , int col , int num){

    int rowfact = row - (row%3);
    int colfact = col - (col%3); 

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if (grid[i+rowfact][j+colfact]==num){
                return false;
            }
        }
    }
    return true;
}

bool ispossible(int grid[n][n] , int row , int col , int num){

    if( ispossibleROW(grid,row,num) && ispossibleCOLUMN(grid,col,num) && ispossibleBOX(grid,row,col,num) ){
        return true;
    }
    return false;

}
bool sudokusolve(int grid[n][n]){
    int row,col;
    if(!isempty(grid , row , col)){
        return true;
    }

    for(int i=0 ; i<n ; i++){

        if(ispossible(grid , row, col , i)){
            grid[row][col]=i;
            if (sudokusolve(grid)){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}


int main(){
    int grid[n][n];

    for(int i=0 ; i<n ; i++){
        string s;
        cin>>s;
        for(int j=0 ; j<n ; j++){
            grid[i][j]= s[j] - '0';
        }
    }
    if (sudokusolve(grid)){
        for(int i=0 ; i<n ; i++ ){
            for(int j=0 ; j<n ; j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
    
}