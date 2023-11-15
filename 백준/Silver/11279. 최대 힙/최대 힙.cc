#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE=1e5;

struct MAX_Heap{
	int heap_array[MAX_SIZE];
	int size=0;

	int parent(int index){
		return (index-1)/2;
	}
	int leftChild(int index){
		return 2*index+1;
	}
	int rightChild(int index){
		return 2*index+2;
	}
	void heapifyUp(int index){
		while(index>0 && heap_array[index]>heap_array[parent(index)]){
			swap(heap_array[index], heap_array[parent(index)]);
			index=parent(index);
		}
	}

	void heapifyDown(int index){
		int Maxindex=index;
		int left=leftChild(index);
		int right=rightChild(index);
		if(left<size && heap_array[left]>heap_array[Maxindex]) Maxindex=left;
		if(right<size && heap_array[right]>heap_array[Maxindex]) Maxindex=right;

		if(index!=Maxindex){
			swap(heap_array[index], heap_array[Maxindex]);
			heapifyDown(Maxindex);
		}
	}

	void insert(int data){
		heap_array[size]=data;
		size++;
		heapifyUp(size-1);
	}

	int extractMax(){
		if(size<=0){
			return 0;
		}
		int Max=heap_array[0];
		heap_array[0]=heap_array[size-1];
		size--;
		heapifyDown(0);
		return Max;
	}
};

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	MAX_Heap max_heap;

	for(int i=0;i<n;i++){
		int cmd; cin >> cmd;
		if(cmd==0){
			int max=max_heap.extractMax();
			cout << max << "\n";
		}
		else{
			max_heap.insert(cmd);
		}
	}
}