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

int send[]={0,0,1,1,2,2};
int receive[]={1,2,0,2,0,1};
bool visited[201][201];
bool ans[201];
int now[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> now[0] >> now[1] >> now[2];

    deque<tuple<int,int,int>> dq;
    dq.push_back({0,0,now[2]});
    ans[now[2]]=true;
    visited[0][0]=true;

    while(!dq.empty()){
        int a,b,c;
        a=get<0>(dq.front());
        b=get<1>(dq.front());
        c=get<2>(dq.front());
        dq.pop_front();

        for(int i=0;i<6;i++){
            int next[]={a,b,c};
            next[receive[i]]+=next[send[i]];
            next[send[i]]=0;

            if(next[receive[i]]>now[receive[i]]){
                next[send[i]]=next[receive[i]]-now[receive[i]];
                next[receive[i]]=now[receive[i]];
            }
            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]]=true;
                dq.push_back({next[0],next[1],now[2]-next[0]-next[1]});
                if(next[0]==0) ans[next[2]]=true;
            }
        }
    }

    for(int i=0;i<201;i++){
        if(ans[i]) cout << i << " ";
    }
    cout << "\n";

}