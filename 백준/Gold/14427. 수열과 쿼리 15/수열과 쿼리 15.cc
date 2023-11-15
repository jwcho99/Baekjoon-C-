#include <stdio.h>
#define MAX_N 100001
typedef struct {
  int first;
  int second;
} pii;

struct pq{
  pii heap[MAX_N];
  int index[MAX_N];
  int heapSize = 0;

  bool heapComp(pii &p1, pii &p2) {
    if(p1.first != p2.first) return p1.first < p2.first;
    else return p1.second < p2.second;
  }

  void swap(pii &p1, pii &p2) {
    pii tmp = p1;
    p1 = p2;
    p2 = tmp;
  }

  void heapSwap(int a, int b) {
    swap(heap[a], heap[b]);
    index[heap[a].second] = a;
    index[heap[b].second] = b;
  }

  void heapPush(pii value) {
  	heap[heapSize] = value;
    index[value.second] = heapSize;
  	heapSize++;
    update(heapSize-1);
  }

  void update(int current){
    while (current>0 && heapComp(heap[current], heap[(current-1)/2])) {
      heapSwap((current-1)/2, current);
  		current = (current-1)/2;
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

  void heapUpdate(int idx, int val) {
    heap[index[idx]].first = val;
    update(index[idx]);
    downdate(index[idx]);
  }

  pii heapPop() {
  	pii value = heap[0];
  	heapSize = heapSize - 1;
  	heap[0] = heap[heapSize];

    downdate(0);
  	return value;
  }
};

int main(){
  pq PQ;
  int N, M, Ai, Query, ii, vv;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &Ai);
    PQ.heapPush({Ai, i});
  }
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d", &Query);
    if(Query == 1){
      scanf("%d %d", &ii, &vv);
      PQ.heapUpdate(ii, vv);
    } else {
      printf("%d\n", PQ.heap[0].second);
    }
  }

  return 0;
}