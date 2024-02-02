#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

vector<ll>color
// 二部グラフかどうかをbfsで判定する関数
bool is_bipartite_graph(vector<vector<int>> &G,ll s){
    color[s]=0;
    queue<int>que;
    que.push(s);
    while(!que.empty()){
        int k=que.front();
        que.pop();
    for(auto t:G[k]){
        if(color[t]!=-1){
            que.push(t);
            if(color[k]==color[t])return false;
            else{color[t]=1-color[k];}
        }
    }
    }
    return true;
}