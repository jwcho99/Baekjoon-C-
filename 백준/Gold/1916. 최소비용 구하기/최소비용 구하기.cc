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

int n, m, start, end_dosi;
vector<int> result;
vector<vector<pair<int,int>>> arr;
vector<bool> visited;

int dijkstra(int s, int e){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    result[s]=0;

    while(!pq.empty()){
        pair<int,int> now=pq.top(); pq.pop();
        if(!visited[now.second]){
            visited[now.second]=true;
            for(pair<int,int> next:arr[now.second]){
                if(!visited[next.second] && result[next.second]>result[now.second]+next.first){
                    result[next.second]=result[now.second]+next.first;
                    pq.push({result[next.second], next.second});
                }
            }
        }
    }
    return result[e];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n+1);
    result=vector<int>(n+1,INT_MAX);
    visited=vector<bool>(n+1,false);

    for(int i=0;i<m;i++){
        int s,e,w; cin >> s >> e >> w;
        arr[s].push_back({w,e});
    }
    cin >> start >> end_dosi;
    int ans = dijkstra(start, end_dosi);
    cout << ans << "\n";

}