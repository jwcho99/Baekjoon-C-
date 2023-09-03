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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> arr(n+1);
    vector<int> degree(n+1,0);
    vector<int> build(n+1);
    vector<int> ans(n+1,0);

    for(int i=1;i<=n;i++){
        cin >> build[i];
        int pre; cin >> pre;
        while(pre!=-1){
            arr[pre].push_back(i);
            degree[i]+=1;
            cin >> pre;
        }
    }

    deque<int> dq;
    for(int i=1;i<=n;i++){
        if(degree[i]==0) dq.push_back(i);
    }

    while(!dq.empty()){
        int now=dq.front(); dq.pop_front();
        for(int x:arr[now]){
            degree[x]-=1;
            ans[x]=max(ans[now]+build[now], ans[x]);
            if(degree[x]==0) dq.push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i]+build[i] << "\n";
    }
}