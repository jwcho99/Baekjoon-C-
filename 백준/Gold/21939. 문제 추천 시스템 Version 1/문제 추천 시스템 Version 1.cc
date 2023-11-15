#include <bits/stdc++.h>
using namespace std;

int n,p,m,l;
bool solved[110001]={false};
int problem_num[110001]={};

struct my_type{
	int level;
	int p_num;
	int index;
};

struct compare1{
	bool operator()(my_type t1, my_type t2){
		if(t1.level==t2.level) return t1.p_num<t2.p_num;
		return t1.level<t2.level;
	}
};

struct compare2{
	bool operator()(my_type t1, my_type t2){
		if(t1.level==t2.level) return t1.p_num>t2.p_num;
		return t1.level>t2.level;
	}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	priority_queue<my_type,vector<my_type>, compare1> pq_hard;
	priority_queue<my_type,vector<my_type>, compare2> pq_easy;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p >> l;
		pq_hard.push({l,p,i});
		pq_easy.push({l,p,i});
		problem_num[p]=i;
	}
	cin >> m;
	for(int i=0;i<m;i++){
		string st;
		int a,b;
		cin >> st;
		if(st=="add"){
			cin >> a >> b;
			pq_hard.push({b,a,i+n});
			pq_easy.push({b,a,i+n});
			problem_num[a]=i+n;
		}
		else if(st=="recommend"){
			cin >> a;
			if(a==1){
				while(solved[pq_hard.top().index]==true){
					pq_hard.pop();
				}
				cout << pq_hard.top().p_num  << "\n";
			}
			else if(a==-1){
				while(solved[pq_easy.top().index]==true){
					pq_easy.pop();
				}
				cout << pq_easy.top().p_num << "\n";
			}
		}
		else if(st=="solved"){
			cin >> a;
			int k = problem_num[a];
			solved[k]=true;
		}
	}
}