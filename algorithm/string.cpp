#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

// 大文字の場合true小文字の場合falseを返す関数
bool upper_string(char c){
    if(c>='A'&&c<='Z'){
        return true;
    }
    else{
        return false;
    }
}

// 小文字を大文字に変換する関数
char upper(char c){
    c=c+('a'-'A');
    return c;
}

// 大文字を小文字に変換する関数
char lower(char c){
    c=c-('a'-'A');
    return c;
}
