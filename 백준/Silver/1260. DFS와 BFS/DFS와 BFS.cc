#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int n,m,v;
vector<vector<int>> arr;
vector<bool> visited;

void DFS(int v);
void BFS(int v);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> v;
    arr=vector<vector<int>>(n+1);
    visited=vector<bool>(n+1,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<n+1;i++){
        sort(arr[i].begin(), arr[i].end());
    }
    DFS(v);
    visited=vector<bool>(n+1,false);
    cout << "\n";
    BFS(v);
}

void DFS(int v){
    cout << v << " ";
    visited[v]=true;
    for(int x:arr[v]){
        if(!visited[x]) DFS(x);
    }
}

void BFS(int v){
    queue<int> q;
    q.push(v);
    visited[v]=true;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        cout << k << " ";
        for(int x:arr[k]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}