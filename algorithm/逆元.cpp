#include <bits/stdc++.h>
using namespace std;
#define ll long long

//mod m でのaの逆元を求めるアルゴリズム
ll modinv(ll a,ll m){
  ll b=m,u=1,v=0;
  while(b){
    ll t=a/b;
    a-=t*b;swap(a,b);
    u-=t*v;swap(u,v);
  }
  u%=m;
  if(u<0){u+=m;}
  return u;
}