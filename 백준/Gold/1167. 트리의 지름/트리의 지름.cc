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

int v;
vector<vector<pair<int,int>>> al;
vector<bool> visited;
vector<int> dis;

void bfs(int start){
    deque<int> dq;
    dq.push_back(start);
    visited[start]=true;

    while(!dq.empty()){
        int st=dq.front();
        dq.pop_front();
        for(auto next:al[st]){
            int a,b;
            a=next.first; b=next.second;
            if(!visited[a]){
                visited[a]=true;
                dis[a]=dis[st]+b;
                dq.push_back(a);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v;
    al.resize(v+1);
    for(int i=1;i<=v;i++){
        int s; cin >> s;
        while(true){
            int e, len;
            cin >> e;
            if(e==-1) break;
            cin >> len;
            al[s].push_back({e,len});
        }
    }
    visited=vector<bool>(v+1, false);
    dis=vector<int>(v+1,0);
    bfs(1);
    //int cmp=*max_element(dis.begin(), dis.end());
    int cmp=1;
    for(int i=2;i<=v;i++){
        if(dis[cmp]<dis[i]) cmp=i;
    }
    
    fill(dis.begin(), dis.end(), 0);
    fill(visited.begin(), visited.end(), false);
    bfs(cmp);
    sort(dis.begin(), dis.end());
    cout << dis[v] << "\n"; 

}