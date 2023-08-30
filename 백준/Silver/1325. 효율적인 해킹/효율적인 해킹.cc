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

int n,m;
vector<vector<int>> arr;
vector<bool> visited;
vector<int> ans;

int bfs(int target){
    int cnt=1;
    deque<int> dq;
    dq.push_back(target);
    visited[target]=true;

    while(!dq.empty()){
        int now=dq.front(); dq.pop_front();
        for(int i:arr[now]){
            if(!visited[i]){
                visited[i]=true;
                dq.push_back(i);
                cnt+=1;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n+1);
    visited = vector<bool>(n+1, false);
    ans = vector<int>(n+1, 0);

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        arr[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        fill(visited.begin(), visited.end(), false);
        ans[i]=bfs(i);
        cout << flush;
    }
    int Max_cnt=-1;
    for(int i=1;i<=n;i++){
        if(Max_cnt<ans[i]) Max_cnt=ans[i];
    }

    for(int i=1;i<=n;i++){
        if(Max_cnt==ans[i]) cout << i << " ";
    }
    cout << "\n"; 

}