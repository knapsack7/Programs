#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)

void printBoard(int board[][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int board[][10],int i,int j,int n){
    //check for column.. NO Need to check for rows
    for(int row=0;row<n;++row){
        if(board[row][j]==1)
            return false;
    }

    //check for left diagonal to the upper part of considered row
    for(int row=i,col=j;row>=0&&col>=0;row--,col--){
        if(board[row][col]==1)
            return false;
    }

    //check for right diagonal to the upper part of considered row
    for(int row=i,col=j;row<=0&&col<n;row--,col++){
        if(board[row][col]==1)
            return false;
    }

    //else Position is Safe

    return true;

}

bool solveNQueen(int board[][10],int i,int n){
    //base Case
    if(i==n){//it means we have successfully placed all queens and so we print the board
        printBoard(board,n);
        cout<<endl;
        return true;
    }
    //Recursive Case
    for(int k=0;k<n;++k){
        if(isSafe(board,i,k,n)){
            board[i][k]=1;
            solveNQueen(board,i+1,n);
            board[i][k]=0;
        }
    }
}


int main(){

int n=0;

cin>>n;

int board[10][10]={0};

solveNQueen(board,0,n);

return 0;
}
