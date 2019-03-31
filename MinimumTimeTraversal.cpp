#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<int>> wormholes;
int test=0;
int noWorm=0;
int rx1=0,ry1=0,rx2=0,ry2=0;
int minDist(int n,int ind,int s1,int s2,int d1,int d2,int c){

    if(d1==rx2 && d2==ry2){
        return abs(s1-d1)+abs(s2-d2)+c;
    }

    int ans=abs(s1-d1)+abs(s2-d2)+c;
    for(vector<int> v=wormholes[ind];ind<n;++ind){
        int ns1=v[ind][2];int ns2=v[ind][3];
        int nd1=v[ind+1][0];int nd2=v[ind+1][1];int nc=v[ind+1,4];
        ans=min(ans,minDist(n,ind+1,ns1,ns2,ny1,ny2,nc));
    }
    return ans;
}

int main() {
    cin>>test;
    for(int j=0;j<test;++j){
        cin>>noWorm;
        cin>>rx1>>ry1>>rx2>>ry2;
        vector<int> v;
        v.pb(rx1);v.pb(ry1);v.pb(rx2);v.pb(ry2);
        v.pb(abs(rx1-rx2)+abs(ry1-ry2));
        wormholes.pb(v);
        v.clear();
        int tx1=0,ty1=0,tx2=0,ty2=0,tc=0;
        for(int i=0;i<noWorm;++i){
            cin>>tx1>>ty1>>tx2>>ty2>>tc;
            v.pb(tx1);v.pb(tx2);v.pb(ty1);v.pb(ty2);v.pb(tc);
            sort(v.begin(),v.begin()+4);
            wormholes.pb(v);
            v.clear();
        }
        sort(wormholes.begin(),wormholes.end());
        /*for(vector<int> v:wormholes){
            for(int i:v){
                cout<<i<<" ";
            }
        cout<<endl;
        }*/

        if(noWorm==0){
            printf("#%d : %d\n",(j+1),wormholes[0][4]);
        }
        else{
            int ans=minDist(n,1,rx1,rx2,wormholes[1][0],wormholes[1][1],wormholes[1][4]);
            printf("#%d : %d\n",(j+1),ans);
        }
        wormholes.clear();
    }
	return 0;
}
