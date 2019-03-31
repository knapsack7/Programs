#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define mk make_pair
ll n=0;
ll chessBoard[10][10]={0};
ll start_i=0,start_j=0;
ll notReachableCells=0;
void solve(){
    queue<pair<ll,ll>> q;
    q.push(mk(start_i,start_j));
    chessBoard[start_i][start_j]=-1;
    while(!q.empty()){
        pair<ll,ll> t=q.front();
        q.pop();
        ll r=t.first,c=t.second;
        if(r-2>=0 && c-1<=9 && chessBoard[r-2][c-1] !=0 &&chessBoard[r-2][c-1] !=-1){
            chessBoard[r-2][c-1]=-1;
            q.push(mk(r-2,c-1));
        }
        if(r-2>=0 && c+1<=9 && chessBoard[r-2][c+1] !=0 &&chessBoard[r-2][c+1] !=-1){
            chessBoard[r-2][c+1]=-1;
            q.push(mk(r-2,c+1));
        }
        if(r-1>=0 && c-2<=9 && chessBoard[r-1][c-2] !=0 &&chessBoard[r-1][c-2] !=-1){
            chessBoard[r-1][c-2]=-1;
            q.push(mk(r-1,c-2));
        }
        if(r-1>=0 && c+2<=9 && chessBoard[r-1][c+2] !=0 &&chessBoard[r-1][c+2] !=-1){
            chessBoard[r-1][c+2]=-1;
            q.push(mk(r-1,c+2));
        }
        if(r+1>=0 && c-2<=9 && chessBoard[r+1][c-2] !=0 &&chessBoard[r+1][c-2] !=-1){
            chessBoard[r+1][c-2]=-1;
            q.push(mk(r+1,c-2));
        }
        if(r+1>=0 && c+2<=9 && chessBoard[r+1][c+2] !=0 &&chessBoard[r+1][c+2] !=-1){
            chessBoard[r+1][c+2]=-1;
            q.push(mk(r+1,c+2));
        }
        if(r+2>=0 && c-1<=9 && chessBoard[r+2][c-1] !=0 &&chessBoard[r+2][c-1] !=-1){
            chessBoard[r+2][c-1]=-1;
            q.push(mk(r+2,c-1));
        }
        if(r+2>=0 && c+1<=9 && chessBoard[r+2][c+1] !=0 &&chessBoard[r+2][c+1] !=-1){
            chessBoard[r+2][c+1]=-1;
            q.push(mk(r+2,c+1));
        }
    }
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            if(chessBoard[i][j]!=0 && chessBoard[i][j]==1)
                notReachableCells++;
        }
    }
}

int main(){
sl(n);

for(ll i=0;i<n;++i){
    for(ll j=0;j<n;++j){
        sl(chessBoard[i][j]);
        if(start_i==0 && start_j==0 && chessBoard[i][j]==0){
            start_i=i;start_j=j;
        }
    }
}
solve();
cout<<notReachableCells<<endl;
return 0;
}
