#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

// X^N
ll originalPow(ll X,ll N){
    ll ans=1;
    while(N>0){
        if(N&1){ans*=X;}
        X*=X;
        N>>1;
    }
    return ans;
}