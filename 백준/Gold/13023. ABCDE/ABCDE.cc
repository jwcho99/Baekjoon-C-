#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> v;
vector<int> visited;
int ans=0;

void DFS(int i, int depth);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    v=vector<vector<int>>(n);
    visited=vector<int>(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        DFS(i,1);
        if(ans) break;
    }
    cout << ans << "\n";
    
}

void DFS(int i, int depth){
    if(depth==5 || ans==1){
        ans=1;
        return;
    }
    visited[i]=1;

    for(int x:v[i]){
        if(!visited[x]){
            DFS(x,depth+1);
        }
    }
    visited[i]=0;
}