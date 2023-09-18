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

    vector<vector<pair<int,int>>> arr(n+1);
    vector<vector<pair<int,int>>> reverse_arr(n+1);
    vector<int> degree(n+1);

    for(int i=0;i<m;i++){
        int start,end,weight;
        cin >> start >> end >> weight;
        arr[start].push_back({end, weight});
        reverse_arr[end].push_back({start,weight});
        degree[end]++;
    }
    int start_dosi, end_dosi; cin >> start_dosi >> end_dosi;

    deque<int> dq;
    dq.push_back(start_dosi);
    vector<int> result_time(n+1);

    while(!dq.empty()){
        int from_dosi=dq.front(); dq.pop_front();

        for(pair<int,int> next:arr[from_dosi]){
            degree[next.first]--;
            result_time[next.first]=max(result_time[next.first], result_time[from_dosi]+next.second);

            if(degree[next.first]==0) dq.push_back(next.first);
        }
    }
    int ans=0;
    vector<bool> visited(n+1);
    deque<int> dq2;
    dq2.push_back(end_dosi);
    visited[end_dosi]=true;

    while(!dq2.empty()){
        int from_dosi=dq2.front(); dq2.pop_front();
        for(pair<int,int> next : reverse_arr[from_dosi]){
            if(result_time[next.first]==result_time[from_dosi]-next.second){
                ans++;
                if(!visited[next.first]){
                    dq2.push_back(next.first);
                    visited[next.first]=true;
                }
            }
        }
    }
    cout << result_time[end_dosi] << "\n" << ans << "\n";
}