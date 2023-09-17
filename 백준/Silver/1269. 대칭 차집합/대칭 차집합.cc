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

const int SIZE=2e5+4;
const int MOD=1e5+7;

struct Nodepool{
    Nodepool* next;
    int data;
}nodepool[SIZE];

int nodecnt;
Nodepool* getNode(int d){
    nodepool[nodecnt].next=NULL;
    nodepool[nodecnt].data=d;
    return &nodepool[nodecnt++];
}
struct Hash{
    Nodepool* head[MOD];
    void push(int data){
        int h=data%MOD;
        Nodepool* node=getNode(data);

        node->next=head[h];
        head[h]=node;
    }
    bool find(int key){
        int h=key%MOD;

        Nodepool* cur=head[h];
        while(cur){
            if(cur->data==key) return true;
            cur=cur->next;
        }
        return false;
    }
}hashMap;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    int input;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> input;
        hashMap.push(input);
    }

    int cnt=0;
    for(int i=0;i<m;i++){
        cin >> input;
        cnt+=hashMap.find(input);
    }

    cout << n+m-2*cnt << "\n";

}