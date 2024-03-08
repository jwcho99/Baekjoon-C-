#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int tree[100001 * 4];
bool lazy[100001 * 4] = { false };

void lazy_update(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		lazy[node] = false;
	}
}

void range_update(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (start > right || end < left) return;
	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}
	int mid = (start + end) / 2;
	range_update(node * 2, start, mid, left, right);
	range_update(node * 2 + 1, mid + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int left_sum = query(node * 2, start, mid, left, right);
	int right_sum = query(node * 2 + 1, mid + 1, end, left, right);
	return left_sum + right_sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int o, s, t; cin >> o >> s >> t;
		s--, t--;
		if (o == 0) {
			range_update(1, 0, n - 1, s, t);
		}
		else if (o == 1) {
			cout << query(1, 0, n - 1, s, t) << "\n";
		}
	}

}