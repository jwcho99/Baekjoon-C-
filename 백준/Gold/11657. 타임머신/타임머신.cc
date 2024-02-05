#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
struct Node {
	int start, end, weight;
};

Node node[6000];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, w; cin >> s >> e >> w;
		node[i].start = s - 1, node[i].end = e - 1, node[i].weight = w;
	}

	vector<int> result(n, INT_MAX);
	result[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int s, e, w;
			s = node[j].start, e = node[j].end, w = node[j].weight;
			if (result[s] == INT_MAX) continue;
			result[e] = min(result[e], result[s] + w);
		}
	}
	int ans = 0;
	bool cycle = false;

	for (int i = 0; i < m; i++) {
		int s, e, w;
		s = node[i].start, e = node[i].end, w = node[i].weight;
		if (result[s] == INT_MAX) continue;
		if (result[e] > result[s] + w) {
			cycle = true; break;
		}
	}

	if (cycle) cout << -1 << "\n";
	else {
		for (int i = 1; i < n; i++) {
			if (result[i] == INT_MAX) cout << -1 << "\n";
			else cout << result[i] << "\n";
		}
	}

}