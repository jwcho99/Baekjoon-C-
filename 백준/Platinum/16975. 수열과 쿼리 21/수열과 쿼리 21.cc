#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
constexpr int MAX = 100001;

ll n,m;
int arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];

void seg_init(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	seg_init(node * 2, start, mid);
	seg_init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void lazy_update(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void range_update(int node, int start, int end, int left, int right, int value) {
	lazy_update(node, start, end);
	if (start > right || end < left) return;
	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * value;
		if (start != end) {
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	int mid = (start + end) / 2;
	range_update(node * 2, start, mid, left, right, value);
	range_update(node * 2 + 1, mid + 1, end, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll get_query(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	ll left_sum = get_query(node * 2, start, mid, left, right);
	ll right_sum = get_query(node * 2 + 1, mid + 1, end, left, right);
	return left_sum + right_sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	seg_init(1, 0, n - 1);
	cin >> m;
	while (m--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int i, j, k; cin >> i >> j >> k;
			i--, j--;
			range_update(1, 0, n - 1, i, j, k);
		}
		else if (cmd == 2) {
			int i; cin >> i;
			i--;
			cout << get_query(1, 0, n - 1, i, i) << "\n";
		}
	}
}