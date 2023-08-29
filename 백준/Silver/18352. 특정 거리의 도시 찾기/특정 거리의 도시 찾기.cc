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

int n,m,k,x;
vector<vector<int>> arr;
vector<int> ans;
vector<int> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k >> x;
    arr.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    visited=vector<int>(n+1,-1);
    deque<int> dq;
    dq.push_back(x);
    visited[x]=0;

    while(!dq.empty()){
        int start=dq.front(); dq.pop_front();
        for(int i:arr[start]){
            if(visited[i]==-1){
                visited[i]=visited[start]+1;
                dq.push_back(i);
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(visited[i]==k) ans.push_back(i);
    }

    if(ans.empty()) cout << "-1" << "\n";
    else{
        sort(ans.begin(), ans.end());
        for(int i:ans){
            cout << i << "\n";
        }
    }
}