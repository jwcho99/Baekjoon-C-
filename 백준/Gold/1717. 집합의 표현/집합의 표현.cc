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
    for(int i=0;i<=n;i++) parent[i]=i;

    for(int i=0;i<m;i++){
        int cmd[3];
        cin >> cmd[0] >> cmd[1] >> cmd[2];
        if(cmd[0]==0){
            unionfunc(cmd[1], cmd[2]);
        }
        else if(cmd[0]==1){
            bool chk=check(cmd[1], cmd[2]);
            if(chk) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}