/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
ll n=0,m=0;
char maze[1000][1000];
ll poss=0,isPrint=0;

void print(){
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            if(maze[i][j]==1)
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(ll i,ll j){
    if(i==n-1 && j==m-1){
        maze[i][j]=1;
        if(isPrint==0)
            print();
        isPrint=1;
        poss=1;
        return;
    }
    if(maze[i][j]=='O')
        maze[i][j]=1;
    else
        return;
    solve(i,j+1);
    solve(i+1,j);
    maze[i][j]='O';
}


int main(){
    sl(n);sl(m);
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            cin>>maze[i][j];
        }
    }
    solve(0,0);
    if(poss==0){
        cout<<-1<<endl;
    }
    return 0;
}
*/

//Not giving TLE if N and M have value approx 1000
#include<iostream>
#include<list>
#include<string.h>
using namespace std;
//const int m=2,n=2;
char board[1000][1000];
int board_path[1000][1000]={0};
list<int> listy;
int count=0;
int move(int row,int col,int r,int c)
{
	board_path[row][col]=1;
	if(row==(r-1) && col==(c-1))
	{
		return 0;
	}
	int a[2]={0,1};
	int b[2]={1,0};
	for(int i=0;i<2;i++)
	{
		if(board[row+a[i]][col+b[i]]=='O' && row+a[i]<=(r-1) && col+b[i]<=(c-1))
		{
			int result=move(row+a[i],col+b[i],r,c);
			if(result==0)// Ensuring that once destination reached no further calls
			{
				return 0;
			}
		}
	}
	board_path[row][col]=0;
	count=count-1;
	return 1;
}
int main()
{
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>board[i][j];
		}
	}
	int result=move(0,0,r,c);
	if(result!=0)
	{
		cout<<"-1";
	}
	else
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cout<<board_path[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
