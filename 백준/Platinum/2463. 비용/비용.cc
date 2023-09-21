#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
#include <limits.h>
using namespace std;

using ll = long long;
const int Size=1e6+1;
ll Mod=1e9;
int n,m;
ll parent[Size];

struct Unionfind{
    void init(int n){
        for(int i=0;i<=n;i++) parent[i]=-1;
    }
    int find(int x){
        if(parent[x]<0) return x;
        return parent[x]=find(parent[x]);
    }
    void merge(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(-parent[a]>-parent[b]){
            parent[a]+=parent[b];
            parent[b]=a;
        }
        else{
            parent[b]+=parent[a];
            parent[a]=b;
        }
    }
}uf;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    int x,y,w;
    vector<pair<int,pair<int,int>>> edges;
    ll total=0;
    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        edges.push_back({w,{x,y}});   
        total+=w;
    }
    uf.init(n);
    sort(edges.begin(), edges.end());
    ll ans=0;
    for(int i=m-1;i>=0;i--){
        int start,end,weight;
        weight=edges[i].first;
        pair<int,int> edge=edges[i].second;
        start=edge.first;
        end=edge.second;
        start=uf.find(start);
        end=uf.find(end);

        if(start!=end){
            ans+=(total*((parent[start]*parent[end])%Mod))%Mod;
            ans%=Mod;
            uf.merge(start,end);
        }
        total-=weight;
    }
    cout << ans << "\n";  
}