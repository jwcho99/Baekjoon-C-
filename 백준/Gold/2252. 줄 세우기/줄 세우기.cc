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

    int n,m; cin >> n >> m;
    vector<vector<int>> arr(n+1);
    vector<int> degree(n+1,0);

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        arr[a].push_back(b);
        degree[b]+=1;
    }
    deque<int> dq;
    for(int i=1;i<=n;i++){
        if(degree[i]==0) dq.push_back(i);
    }

    while(!dq.empty()){
        int now=dq.front(); dq.pop_front();
        cout << now << " ";
        for(int x:arr[now]){
            degree[x]-=1;
            if(degree[x]==0) dq.push_back(x);
        }
    }
    cout << "\n";
}