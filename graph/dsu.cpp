#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

// atcoder libraryを理解するため
struct dsu{
    // public:クラス外、クラス内、派生クラスからアクセス可能
    // 外部のプログラムコードから自由に読み書きすることが可能
    public:
        dsu() : _n(0) {}
        // explicit:コピーの初期化が出来なくなる　暗黙の型変換が出来ない
        explicit dsu(int n): _n(n), parent_or_size(n,-1){}

        int merge(int a, int b){
            // assert関数：真ならば何も起こらないが、偽の場合はプログラムを終了させる
            assert(0<=a && a< _n);
            assert(0<=b && b <_n);
            int x=leader(a),y=leader(b);
            if(x==y)return x;
            if(-parent_or_size[x]<-parent_or_size[y])swap(x,y);
            parent_or_size[x]+=parent_or_size[y];
            parent_or_size[y]=x;
            return x;
        }
        bool same(int a,int b){
            assert(0<=a&&a<_n);
            assert(0<=b&&b<_n);
            return leader(a)==leader(b);
        }

        int leader(int a){
            assert(0<=a&&a<_n);
            if(parent_or_size[a]<0)return a;
            return parent_or_size[a]=leader(parent_or_size[a]);
        }

        int size(int a){
            assert(0<=a&&a<_n);
            return -parent_or_size[leader(a)];
        }
        vector<vector<int>>groups(){
            vector<int>leader_buf(_n),group_size(_n);
            for(int i=0;i<_n;i++){
                leader_buf[i]=leader(i);
                group_size[leader_buf[i]]++;
            }
            vector<vector<int>>result(_n);
            for(int i=0;i<_n;i++){
                result[i].reserve(group_size[i]);
            }
            for(int i=0;i<_n;i++){
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                remove_if(result.begin(),result.end(),
                            [&](const vector<int>&v){return v.empty();}),
                result.end());
            return result;
        }
    private:
        int _n;
        vector<int>parent_or_size;
};