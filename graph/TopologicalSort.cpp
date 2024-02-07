#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)


//求めたいトポロジカルソートしたものが辞書順の場合、queueの代わりに
// priority_queueを使う
vector<ll>topological_sort(const vector<vector<ll>>&G){
    const ll n=G.size();
    vector<ll>deg(n);
    for(ll v=0;v<n;v++){
        for(auto nv:G[v]){
            deg[nv]++;
        }
    }
    vector<ll>res;
    queue<ll>que;
    for(ll v=0;v<n;v++){
        if(deg[v]==0){
            que.push(v);
            res.push_back(v);
        }
    }
    while(!que.empty()){
        ll v=que.front();que.pop();
        for(auto nv:G[v]){
            deg[nv]--;
            if(deg[nv]==0){
                que.push(nv);
                res.push_back(nv);
            }
        }
    }
    return res;
}