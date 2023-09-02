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
    if(a!=b) parent[b]=a;
}
bool check(int a, int b){
    a=find(a); b=find(b);
    if(a==b) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    vector<int> route(m+1,0);
    vector<vector<int>> connect(n+1, vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> connect[i][j];
        }
    }

    for(int i=1;i<=m;i++) cin >> route[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(connect[i][j]==1){
                unionfunc(i,j);
            }
        }
    }

    bool flag=true;
    int index=find(route[1]);
    for(int i=2;i<=m;i++){
        if(index!=find(route[i])){
            flag=false;
            break;
        }
    }

    if(flag) cout << "YES";
    else cout << "NO";
}