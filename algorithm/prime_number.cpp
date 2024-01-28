#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
// 素数判定する関数
bool is_prime(ll n){
    if(n==1){return false;}
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// 約数を列挙する関数
vector<ll> divisor(ll n){
    vector<ll>ans;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(i!=n/i){
                ans.push_back(n/i);
            }
        }
    }
}

// エラトステネスの篩
vector<ll> elatosthenes(ll N){
    vector<ll>ans;
    if(N==1){return ans;}
    vector<bool>seen(N+1,false);
    for(ll i=2;i<=N;i++){
        if(!seen[i]){
            ans.push_back(i);
            for(ll j=i;j<=N;j+=i){
                seen[j]=true;
            }
        }
    }
    return ans;
}