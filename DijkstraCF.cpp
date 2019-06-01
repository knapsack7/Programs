#include <bits/stdc++.h>
using namespace std;
#define inf 1e15
#define pii pair<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define ll long long
long long dis[100001];
vector<pii> g[100001];
long long pa[100001], w, v, u, cost;
long long dijkstra(long long s){
    dis[s] = 0;
    set<pii> q;
    q.insert({dis[s], s});
    while (!q.empty()){
        w = (*q.begin()).ff;
        u = (*q.begin()).ss;
        q.erase(q.begin());
        for (long long i = 0; i < g[u].size(); i++){
            v = g[u][i].ff;
            cost = g[u][i].ss;
            if (w + cost < dis[v]){
                q.erase({dis[v] ,v});
                dis[v] = w + cost;
                q.insert({dis[v], v});
                pa[v] = u;
            }
        }
    }
}
void ans(long long x){
    if (x == -1)
        return;
    ans(pa[x]);
    cout << x << " ";
}
int main(){
    long long node, edge, x, y, w, s, i;
    cin >> node >> edge;
    for (i = 0; i < edge; i++){
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    for (i = 0; i <= node; i++){
        dis[i] = LLONG_MAX;
        pa[i] = -1;
    }
    dijkstra(1);
    if (node == 1)
        cout << 0 << endl;
    else if (pa[node] == -1)
        cout << -1 << endl;
    else
        ans(node);
    return 0;
}
