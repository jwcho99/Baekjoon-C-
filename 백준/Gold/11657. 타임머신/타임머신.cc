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
#include <limits.h>
using namespace std;

struct Node{
    int start,end,weight;
};

Node* getNode(int s, int e, int w){
    Node* node=(Node*)malloc(sizeof(Node));
    node->start=s;
    node->end=e;
    node->weight=w;
    
    return node;
}

int n,m;
vector<long long> dis;
vector<Node*> edges;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    dis.resize(n+1);
    fill(dis.begin(), dis.end(), LONG_LONG_MAX);

    for(int i=0;i<m;i++){
        int st,en,we; cin >> st >> en >> we;
        edges.push_back(getNode(st,en,we));
    }

    dis[1]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            Node* now = edges[j];
            if(dis[now->start]!=LONG_LONG_MAX && dis[now->end]>dis[now->start]+now->weight){
                dis[now->end]=dis[now->start]+now->weight;
            }
        }
    }
    bool cycle_chk=false;

    for(int i=0;i<m;i++){
        Node* chk=edges[i];
        if(dis[chk->start]!=LONG_LONG_MAX && dis[chk->end]>dis[chk->start]+chk->weight){
            cycle_chk=true;
        }
    }
    if(!cycle_chk){
        for(int i=2;i<=n;i++){
            if(dis[i]==LONG_LONG_MAX) cout << -1 << "\n";
            else cout << dis[i] << "\n";
        }
    }
    else cout << -1 << "\n";
}