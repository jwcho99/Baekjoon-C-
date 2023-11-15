#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, less<int>> pq;
	cin >> n;

	for(int i=0;i<n;i++){
		int cmd; cin >> cmd;
		if(cmd == 0){
			if(pq.empty()){
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
		else{
			pq.push(cmd);
		}
	}

}