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
int hashn;
vector<vector<int>> hash_table;

void addfunc(int target){
    int k=target%hashn;
    hash_table[k].push_back(target);
}

bool search(int target){
    int k=target%hashn;
    if(hash_table[k].size()==0) return false;
    else{
        for(int x:hash_table[k]){
            if(x==target) return true;
        }
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    if(n>=m) hashn=n;
    else hashn=m;

    //vector<vector<int>> hash_table(hashn+1);
    hash_table = vector<vector<int>>(hashn+1);
    
    int cmd;
    for(int i=0;i<n;i++){
        cin >> cmd;
        addfunc(cmd);
    }

    int total=0;
    for(int i=0;i<m;i++){
        cin >> cmd;
        if(search(cmd)) total+=1;
    }
    cout << n+m-2*total << "\n";

}