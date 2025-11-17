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
        g[v].push_back({u,w});
    }

    vector<int> vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});
    int cost=0;

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int w=t.first, u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        cost+=w;
        for(auto &p:g[u])
            if(!vis[p.first]) pq.push({p.second,p.first});
    }
    cout<<cost;
}
