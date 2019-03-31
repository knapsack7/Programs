#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number){
    for(int x=0;x<n;++x){//checking row and column
        if(mat[i][x]==number||mat[x][j]==number){
            return false;
        }
    }
    //checking submatrix of size 3*3

    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;

    for(int x=sx;x<sx+rn;++x){
        for(int y=sy;y<sy+rn;++y){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
    if(i==n){
        //Print matrix and return
        for(int x=0;x<n;++x){
            for(int y=0;y<n;++y){
                cout<<mat[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //case row end
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    //ignore the cell if it is not blank
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    //Recursion case
    //Fill the blank with possible options
    for(int x=1;x<=n;++x){
        if(canPlace(mat,i,j,n,x)){
            mat[i][j]=x;
            bool couldWeSolve=solveSudoku(mat,i,j+1,n);
            if(couldWeSolve){
                return true;
            }
        }
    }
    mat[i][j]=0;
    return false;
}

int main(){

int mat[9][9]={
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
            };
    solveSudoku(mat,0,0,9);
    return 0;
}
