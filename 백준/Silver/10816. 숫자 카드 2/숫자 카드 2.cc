#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[500001];

int cnt_num(int key){
	int l = lower_bound(arr, arr+n, key)-arr;
	int u = upper_bound(arr, arr+n, key)-arr;
	return u-l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cin >> m;
	int k;
	int ans=0;
	for(int i=0;i<m;i++){
		cin >> k;
		ans = cnt_num(k);
		cout << ans << " ";
	}
	cout << "\n";	
}