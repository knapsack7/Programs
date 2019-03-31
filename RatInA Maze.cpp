#include<bits/stdc++.h>
using namespace std;
int n=4,m=4;
int cellCovered=0;
int noOfPath=0;
int Maze[10][10]={0};
void printPath(string *out,int len){
    for(int i=0;i<len;i++)
        cout<<out[i]<<"->";
    cout<<"Which IS DESTINATION"<<endl;
}
void solveRat(int i,int j,string *out,int len){
    if(i==n-1&&j==m-1){
        out[len]=to_string(i)+to_string(j);
        noOfPath++;
        printPath(out,len);
        return;
    }
    if((j+1<m)&&Maze[i][j+1]==0){
        out[len]=to_string(i)+to_string(j+1);;
        solveRat(i,j+1,out,len+1);
    }
    if((i+1<n)&&Maze[i+1][j]==0){
        out[len]=to_string(i+1)+to_string(j);;
        solveRat(i+1,j,out,len+1);
    }
}

int main(){
    string out[100];
    Maze[2][3]=1;//Blocked cell
    Maze[1][2]=1;
    Maze[3][1]=1;
    out[0]="00";//(0,0) is starting position
    solveRat(0,0,out,1);
    cout<<"No of Path Possible are :"<<noOfPath<<endl;
    return 0;
}
