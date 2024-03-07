#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

constexpr int MAX = 1000005;

int n, m, k;
ll tree[MAX * 4];
ll lazy[MAX * 4];
ll arr[MAX];

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

void seg_update(int node, int start, int end, int left, int right, ll value) {
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
	seg_update(node * 2, start, mid, left, right, value);
	seg_update(node * 2 + 1, mid + 1, end, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll seg_query(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	ll left_sum = seg_query(node * 2, start, mid, left, right);
	ll right_sum = seg_query(node * 2 + 1, mid + 1, end, left, right);
	return left_sum + right_sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];
	int cmd_num = m + k;
	seg_init(1, 0, n - 1);
	while (cmd_num--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			ll b, c, d; cin >> b >> c >> d;
			b--, c--;
			seg_update(1, 0, n - 1, b, c, d);
		}
		else if (cmd == 2) {
			ll b, c; cin >> b >> c;
			b--, c--;
			cout << seg_query(1, 0, n - 1, b, c) << "\n";
		}
	}

}