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

struct Node{
    Node* next;
    string string_data;
}node_arr[SIZE];

int nodecnt;
Node* getNode(string data){
    node_arr[nodecnt].next=NULL;
    node_arr[nodecnt].string_data=data;
    return &node_arr[nodecnt++];
}
struct Hash{
    Node* hash[MOD];

    void push(string data){
        int hash_num=0;
        for(int i=0;i<data.size();i++){
            hash_num+=data[i]-'a';
        }
        Node* node=getNode(data);
        node->next=hash[hash_num%MOD];
        hash[hash_num%MOD]=node;
    }
    bool find(string data){
        int hash_num=0;
        for(int i=0;i<data.size();i++){
            hash_num+=data[i]-'a';
        }
        Node* cur=hash[hash_num%MOD];
        while(cur){
            if(cur->string_data==data) return true;
            cur=cur->next;
        }
        return false;
    }
}hashMap;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    string cmd;
    for(int i=0;i<n;i++){
        cin >> cmd;
        hashMap.push(cmd);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        cin >> cmd;
        ans+=hashMap.find(cmd);
    }
    cout << ans << "\n";
}