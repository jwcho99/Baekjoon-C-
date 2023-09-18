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

int n,m,start;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> start;
    vector<vector<pair<int,int>>> arr(n+1);
    vector<int> result(n+1, INT_MAX);

    for(int i=0;i<m;i++){
        int s,e,w; cin >> s >> e >> w;
        arr[s].push_back({w,e});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    result[start]=0;
    vector<bool> visited(n+1, false);

    while(!pq.empty()){
        pair<int,int> now = pq.top(); pq.pop();
        if(visited[now.second]) continue;
        visited[now.second]=true;
        
        for(pair<int,int> next : arr[now.second]){
            if(result[next.second]>result[now.second]+next.first){
                result[next.second]=result[now.second]+next.first;
                pq.push({result[next.second], next.second});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(visited[i]) cout << result[i] << "\n";
        else cout << "INF" << "\n"; 
    }

}