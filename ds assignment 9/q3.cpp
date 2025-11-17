#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1000];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int a,int b){
    a=find(a); b=find(b);
    if(a!=b) parent[b]=a;
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> e;
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        e.push_back({w,u,v});
    }
    sort(e.begin(), e.end());
    int cost=0;

    for(auto &x:e){
        int w=x[0], u=x[1], v=x[2];
        if(find(u)!=find(v)){
            unite(u,v);
            cost+=w;
        }
    }
    cout<<cost;
}
