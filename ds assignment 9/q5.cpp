#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    int s; cin>>s;
    vector<int> dist(n,1e9);
    dist[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int u=t.second, d=t.first;
        if(d!=dist[u]) continue;
        for(auto &p:g[u]){
            int v=p.first, w=p.second;
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int x:dist) cout<<x<<" ";
}
