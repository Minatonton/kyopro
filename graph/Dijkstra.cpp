#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
const ll INF=(1<<60);




vector<vector<pair<int,int>>>G;
// distは距離を表す
vector<ll>dist;
 
// startからdijkstra
void dijkstra(ll s){
    for(auto &x:dist){
        x=INF;
    }
    // {距離、行先}
    priority_queue<pair<ll,ll>>pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        pair<ll,ll>p=pq.top();
        ll d=p.first;
        ll pos=p.second;
        pq.pop();
        if(dist[pos]<d)continue;
        for(auto to_cost:G[pos]){
            ll to=to_cost.first;
            ll cost=to_cost.second;
            if(dist[to]>dist[pos]+cost){
                dist[to]=dist[pos]+cost;
                pq.push({dist[to],to});
            }
        }
    }
}