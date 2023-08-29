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
using namespace std;

int n;
long long lcm;
vector<vector<tuple<int,int,int>>> arr;
vector<bool> visited;
vector<long long> ans;

long long gcd(long long t1, long long t2){
    if(t2==0){
        return t1;
    } 
    else{
        return gcd(t2, t1%t2);
    }
}

void dfs(int target){
    for(tuple<int,int,int> i:arr[target]){
        int next=get<0>(i);
        if(!visited[next]){
            ans[next]=ans[target]*get<2>(i)/get<1>(i);
            visited[next]=true;
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr = vector<vector<tuple<int,int,int>>>(n+1);
    visited = vector<bool>(n+1,false);
    ans = vector<long long>(n+1);
    lcm=1;

    for(int i=0;i<n-1;i++){
        int a,b,p,q; cin >> a >> b >> p >> q;
        arr[a].push_back({b,p,q});
        arr[b].push_back({a,q,p});
        lcm*=(p*q)/gcd(p,q);
    }

    ans[0]=lcm;
    visited[0]=true;
    dfs(0);

    long long k=ans[0];
    for(int i=1;i<n;i++){
        k=gcd(k,ans[i]);
    }

    for(int i=0;i<n;i++){
        cout << ans[i]/k << " ";
    }
    cout << "\n";
}