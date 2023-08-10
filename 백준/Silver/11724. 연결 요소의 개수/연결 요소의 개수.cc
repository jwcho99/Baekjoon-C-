#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

int n,m;
vector<bool> visited;
void dfs(int v);
vector<vector<int>> al;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    al.resize(n+1);
    visited=vector<bool>(n+1, false);

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans+=1;
            dfs(i);
        }
    }
    cout << ans << "\n";
}

void dfs(int v){
    if(visited[v]) return;

    visited[v]=true;
    for(int i:al[v]){
        if(!visited[i]) dfs(i);
    }
}
