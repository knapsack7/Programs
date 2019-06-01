//Note this code works fine for Undirected Graph but you can slighlt modify code
//to work fine for directed graph as well.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class data{
    public:
        bool isadded=0;
        ll dis=INT_MAX;
};

map<ll,ll > dist;
class Graph{
    public:
        unordered_map<ll,set<pair<ll,ll>>> graph;
        void addEdge(ll u,ll v ,ll w,bool bidir=true){
            graph[u].insert(make_pair(v,w));
            if(bidir){
                graph[v].insert(make_pair(u,w));
            }
        }
        void prindGraph(){
            //Let try to print thee ADJ List
            //Iterate over all the key pairs in the map
            for(auto j:graph){
                cout<<j.first<<" ->";
                //Iterate over all the list of cities
                for(auto l:j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";
                }
                cout<<endl;
            }
        }
        void dijsktraSSSP(ll src){
            //Make to set (for Heap functions) to find a node with the minimum  distance
            set<pair<ll,ll> > s;
            dist[src]=0;//Stores final result
            s.insert(make_pair(0,src));
            while(!s.empty()){
                auto p=*(s.begin());
                ll node=p.second;
                ll nodeDist=p.first;//Node distance from parent
                s.erase(s.begin());//Distance to this node (node) is finalised so we removed it. otherwise it will always be considered bz this is
                //the node least value in the set and hence necessary to erase it.
                //Iterate over neighbours/children of the current node
                for(auto childPair:graph[node]){
                    if(nodeDist+childPair.second<dist[childPair.first]){// Distance to neighbours is optimised
                        //Int the set updation of a particular is not possible we have to remove the old Pair,
                        //and insert the new pair for same node to simulate updation
                        ll des=childPair.first;
                        auto f=s.find(make_pair(dist[des],des));
                        if(f!=s.end())
                            s.erase(f);
                        //Insert the new Pair
                        dist[des]=nodeDist+childPair.second;
                        s.insert(make_pair(dist[des],des));
                    }
                }
            }
            //Let print the distances to all other node from src
            for(auto d:dist){
                if(d.first!=src){
                    if(d.second!=INT_MAX)
                        cout<<d.second<<" ";
                    else
                        cout<<"-1"<<" ";
                }
            }
        }
};


int main() {
    ll t=0;
    cin>>t;
    while(t--){
        data mat[3001][3001];
        Graph g;
        ll nodes,edges=0;
        cin>>nodes>>edges;
        for(int i=0;i<edges;++i){
            int u,v,w;
            cin>>u>>v>>w;
            if(!mat[u][v].isadded){
                g.addEdge(u,v,w);
                mat[u][v].isadded=true;
                mat[u][v].dis=w;
            }
            else{
                if(mat[u][v].dis>w){
                    mat[u][v].dis=w;
                    g.addEdge(u,v,w);
                    //g.graph[u][v].second=w;
                    //g.graph[v][u].second=w;
                }
            }

        }
        //g.prindGraph();
        //set all distance to infinity
        for(ll i=1;i<=nodes;++i){// Here you can modify so as to work for directed graph too bz this way it will not consider the node if outdegree from any node is zero
                dist[i]=INT_MAX;
        }
        ll src=0;
        cin>>src;
        g.dijsktraSSSP(src);
        cout<<endl;
    }
    return 0;
}
