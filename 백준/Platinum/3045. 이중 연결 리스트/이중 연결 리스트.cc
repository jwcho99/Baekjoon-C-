#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

struct Node {
    int num;
    struct Node* prev;
    struct Node* next;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;

    Node *node = new Node[n+2];

    Node* head = &node[0];
    Node* tail = &node[n+1];

    for(int i = 1; i <= n; i++){
        node[i].num = i;
        node[i].prev = &node[i-1];
        node[i].next = &node[i+1];
    }
    head->next = &node[1];
    tail->prev = &node[n];

    int x, y;
    char cmd;
    for(int i = 0; i < m; i++){
        cin >> cmd >> x >> y;

        node[x].prev->next = node[x].next;
        node[x].next->prev = node[x].prev;
        if(cmd == 'A'){
            node[x].prev = node[y].prev;
            node[x].next = &node[y];

            node[y].prev->next = &node[x];
            node[y].prev = &node[x];
        } else if(cmd=='B'){
            node[x].prev = &node[y];
            node[x].next = node[y].next;

            node[y].next->prev = &node[x];
            node[y].next = &node[x];
        }
    }

    vector<int> arr;
    vector<int> minLast(n, INF);
    vector<int> location;

    int lisLength = 0;

    Node cur = node[0];
    int i = 0;

    while(cur.next != &node[n+1]){
        cur = *cur.next;
        arr.push_back(cur.num);

        int index = lower_bound(minLast.begin(), minLast.end(), cur.num) - minLast.begin();

        minLast[index] = cur.num;
        location.push_back(index+1);

        lisLength = max(lisLength, index+1);
    }

    vector<int> lis(lisLength+1);
    lis[0] = 0;

    int len = lisLength;
    for(int i = location.size()-1; i >= 0; i--){
        if(location[i] == len){
            lis[len--] = arr[i];
        }
    }

    cout << n - lisLength << '\n';
    int now;
    for(int i = lisLength; i >= 1; i--){
        now = lis[i]-1;

        while(now > lis[i-1]){
            cout << "A " << now << " " << now+1 << "\n";
            now--;
        }
    }

    for(int now = lis.back()+1; now <= n; now++){
        cout << "B " << now << " " << now-1 << "\n";
    }

    return 0;
}