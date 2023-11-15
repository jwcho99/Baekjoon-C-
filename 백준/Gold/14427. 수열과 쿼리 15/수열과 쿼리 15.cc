#include <bits/stdc++.h>
using namespace std;

#define MAX_n 100001

typedef struct{
	int first;
	int second;
}pii;

struct pq{
	pii heap[MAX_n];
	int index[MAX_n];
	int heapSize = 0;

	bool heapComp(pii &p1, pii &p2) {
		if(p1.first != p2.first) return p1.first < p2.first;
		else return p1.second < p2.second;
  	}

	void swap(pii &p1, pii &p2){
		pii tmp=p1;
		p1=p2;
		p2=tmp;
	}

	void heapSwap(int index1, int index2){
		swap(heap[index1], heap[index2]);
		index[heap[index1].second]=index1;
		index[heap[index2].second]=index2;
	}

	void heapPush(pii data){
		heap[heapSize]=data;
		index[data.second]=heapSize;
		heapSize++;
		update(heapSize-1);
	}

	void update(int current){
		while(current>0 && heapComp(heap[current], heap[(current-1)/2])){
			heapSwap((current-1)/2, current);
			current=(current-1)/2;
		}
	}

	void downdate(int current){
		while (current*2+1 < heapSize) {
  			int child;
  			if (current*2+2 == heapSize) child = current*2+1;
  			else child = heapComp(heap[current*2+1], heap[current*2+2]) ? current*2+1 : current*2+2;

  			if (heapComp(heap[current], heap[child])) break;
      		heapSwap(current, child);
  			current = child;
  		}
	}

	void heapUpdate(int idx, int data){
		heap[index[idx]].first=data;
		update(index[idx]);
		downdate(index[idx]);
	}

	pii heapPop(){
		pii value = heap[0];
		heapSize=heapSize-1;
		heap[0]=heap[heapSize];
		downdate(0);
		return value;
	}
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	pq PQ;
  	int N, M, Ai, Query, ii, vv;
 	cin >> N;
  	for (int i = 1; i <= N; i++) {
   		cin >> Ai;
    	PQ.heapPush({Ai, i});
  	}
  	cin >> M;
  	for (int i = 1; i <= M; i++) {
    	cin >> Query;
    	if(Query == 1){
      		cin >> ii >> vv;
      		PQ.heapUpdate(ii, vv);
    	}
		else {
      		cout << PQ.heap[0].second << "\n";
    	}
	}
	return 0;
}
