#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    int num;
    for(int i=0;i<n;i++){
        cin >> num;
        pq.push(num);
    }
    int ans=0;
    while(pq.size()>=2){
        int a,b;
        a=pq.top(); pq.pop();
        b=pq.top(); pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout << ans << "\n";
}