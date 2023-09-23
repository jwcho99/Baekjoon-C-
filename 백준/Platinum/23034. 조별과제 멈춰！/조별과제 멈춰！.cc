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
#include <limits.h>
using namespace std;

#define LL long long
const int MaxN = 1e3+1;
const int MaxM = 1e5+1;

struct Edge{
	int s,e,w;
}edge[MaxM];

vector<pair<int,int>> arr[MaxN];
int dist[MaxN][MaxN];
int n,m,q,mst_ans;

bool cmp(Edge a, Edge b){
	return a.w<b.w;
}

struct UnionFind{
	int parent[MaxN];
	void init(int n){
		for(int i=1;i<=n;i++) parent[i]=i;
	}
	int find(int x){
		return x==parent[x]?x:parent[x]=find(parent[x]);
	}
	void merge(int a, int b){
		a=find(a); b=find(b);
		if(a==b) return;
		else a<b?parent[b]=a:parent[a]=b;
	}
}uf;

void bfs(int start){
	bool visited[MaxN] {};
	visited[start]=true;
	deque<int> dq;
	dq.push_back(start);
	while(!dq.empty()){
		int now=dq.front(); dq.pop_front();
		for(auto [next, cost]:arr[now]){
			if(!visited[next]){
				dist[start][next]=max(max(dist[start][next], dist[start][now]), cost);
				visited[next]=true;
				dq.push_back(next);
			}
		}
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	uf.init(n);

	for(int i=0;i<m;i++){
		cin >> edge[i].s >> edge[i].e >> edge[i].w;
	}
	sort(edge, edge+m, cmp);
	for(int i=0;i<m;i++){
		auto [s,e,c]=edge[i];
		int ps=uf.find(s);
		int pe=uf.find(e);
		if(ps!=pe){
			mst_ans+=c;
			uf.merge(ps,pe);
			arr[s].push_back({e,c});
			arr[e].push_back({s,c});
		}
	}

	for(int i=1;i<=n;i++) bfs(i);

	cin >> q;
	for(int i=0;i<q;i++){
		int qs, qe; cin >> qs >> qe;
		cout << mst_ans-dist[qs][qe] << "\n";
	}
}