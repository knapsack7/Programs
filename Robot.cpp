#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%d",&n)

int maze[50][5]={0};

int robot(int h,int j){
    if(h<0 || j>4){
        return 0;
    }

    int leftupward=maze[h][j]+robot(h-1,j-1);
    int upward=maze[h][j]+robot(h-1,j);
    int rightupward=maze[h][j]+robot(h-1,j+1);
    return max(max(leftupward,upward),rightupward);

}

int main(){
    int t=0;
    sl(t);
    while(t--){
        int h=0;
        memset(maze,0,sizeof(maze));
        sl(h);
        for(int i=0;i<h;++i){
            for(int j=0;j<5;++j){
                sl(maze[i][j]);
                if(i<5 && maze[i][j]==-1){
                    maze[i][j]=0;
                }
            }
        }
        /*for(inti=0;i<h;++i){
            for(intj=0;j<5;++j){
                cout<<maze[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<robot(h,2)<<endl;
    }
    return 0;
}
