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

const int Size=1e5+4;
int n,m;

struct UnionFind{
	int parent[Size];
	void init(int n){
		for(int i=1;i<=n;i++) parent[i]=i;
	}
	int find(int x){
		return x==parent[x]?x:parent[x]=find(parent[x]);
	}
	void union_func(int a, int b){
		a=find(a); b=find(b);
		if(a==b) return;
		else a<b?parent[b]=a:parent[a]=b;
	}
}uf;

struct Edge{
	int x,y,cost;
}edge[Size];

struct Sort{
	Edge tmp[Size+10];

	void merge(int start, int end){
		int i=start,k=start;
		int mid=(start+end)>>1;
		int j=mid+1;
		while(i<=mid && j<=end){
			tmp[k++]=edge[i].cost<edge[j].cost?edge[i++]:edge[j++];
		}
		while(i<=mid) tmp[k++]=edge[i++];
		while(j<=end) tmp[k++]=edge[j++];

		for(int idx=start;idx<=end;idx++) edge[idx]=tmp[idx];
	}
	void divide(int start, int end){
		if(start>=end) return;

		int mid=(start+end)>>1;
		divide(start,mid);
		divide(mid+1, end);
		merge(start, end);
	}

	void sort_func(int e){
		divide(0,e-1);
	}
}st;

struct MST{
	int solve(int v, int e){
		uf.init(v);
		st.sort_func(e);

		int ans=0;
		for(int i=0;i<e;i++){
			int xx=uf.find(edge[i].x);
			int yy=uf.find(edge[i].y);

			if(xx==yy) continue;

			ans+=edge[i].cost;
			uf.union_func(xx,yy);
		}
		return ans;
	}

}mst;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int s, e, c;
		cin >> s >> e >> c;
		edge[i].x=s, edge[i].y=e, edge[i].cost=c;
	}

	int result = mst.solve(n,m);
	cout << result << "\n";

}