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
vector<int> parent;

int find(int target){
    if(target==parent[target]) return target;
    else return parent[target]=find(parent[target]);
}
void unionfunc(int a, int b){
    a=find(a); b=find(b);
    if(a!=b){
        if(a<=b) parent[b]=a;
        else parent[a]=b;
    }
}
bool check(int a, int b){
    a=find(a); b=find(b);
    if(a==b) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int n,m;
    cin >> n >> m;
    vector<int> know;
    vector<vector<int>> group(m);

    parent.resize(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;

    int k; cin >> k;
    for(int i=0;i<k;i++){
        int cmd; cin >> cmd;
        know.push_back(cmd);
        parent[cmd]=0;
    }


    for(int i=0;i<m;i++){
        int cnt; cin >> cnt;
        int first_person; cin >> first_person;
        group[i].push_back(first_person);
        for(int j=1;j<cnt;j++){
            int who; cin >> who;
            group[i].push_back(who);
            unionfunc(group[i][0], group[i][j]);
        }
    }
    int ans=m;

    for(int i=0;i<m;i++){
        for(int j=0;j<group[i].size();j++){
            if(find(group[i][j])==0){
                ans-=1;
                break;
            }
        }
    }
    cout << ans << "\n";


}