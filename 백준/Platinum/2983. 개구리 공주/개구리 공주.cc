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
using namespace std;

const int SIZE=2e5;
int n,k;
char cmd[SIZE];

struct NODE{
    int x,y;
    NODE *A, *B, *C, *D;
}node[SIZE];

NODE* frog;

int idx[SIZE], tmp[SIZE];

int compsum(int a, int b){
    int sum_a=node[a].x+node[a].y;
    int sum_b=node[b].x+node[b].y;
    if(sum_a==sum_b) return node[a].x<node[b].x;
    return sum_a<sum_b;
}

int compdif(int a, int b){
    int dif_a=node[a].x-node[a].y;
    int dif_b=node[b].x-node[b].y;
    if(dif_a==dif_b) return node[a].x<node[b].x;
    return dif_a<dif_b;
}

void mergesort(int start, int end, int ((*comp)(int,int))){
    if(start>=end) return;
    int i=start, k=start, mid=(start+end)/2, j=mid+1;
    mergesort(start,mid,comp);
    mergesort(mid+1,end,comp);
    while(i<=mid && j<=end){
        if(comp(idx[i], idx[j])) tmp[k++]=idx[i++];
        else tmp[k++]=idx[j++];
    }
    while(i<=mid) tmp[k++]=idx[i++];
    while(j<=end) tmp[k++]=idx[j++];
    for(int t=start;t<=end;t++) idx[t]=tmp[t];
}
void input(){
    cin >> n >> k;
    string st; cin >> st;
    for(int i=0;i<k;i++){
        cmd[i]=st[i];
    }
    for(int i=1;i<=n;i++){
        int nx,ny; cin >> nx >> ny;
        node[i].x=nx; node[i].y=ny;
        node[i].A=node[i].B=node[i].C=node[i].D=NULL;
    }
}

void connect(){
    for(int i=1;i<=n;i++){
        idx[i]=i;
    }
    mergesort(1,n,compsum);
    for(int i=1;i<n;i++){
        NODE* cur=&node[idx[i]];
        NODE* next=&node[idx[i+1]];
        if((cur->x+cur->y)==(next->x+next->y)){
            cur->B=next;
            next->C=cur;
        }
    }
    mergesort(1,n,compdif);
    for(int i=1;i<n;i++){
        NODE* cur=&node[idx[i]];
        NODE* next=&node[idx[i+1]];
        if((cur->x-cur->y)==(next->x-next->y)){
            cur->A=next;
            next->D=cur;
        }
    }
}

void delfrog(NODE* f){
    if(f->A) f->A->D=f->D;
    if(f->B) f->B->C=f->C;
    if(f->C) f->C->B=f->B;
    if(f->D) f->D->A=f->A;
}

void jump(){
    frog=&node[1];

    for(int i=0;i<k;i++){
        if(cmd[i]=='A'){
            if(frog->A){
                delfrog(frog);
                frog=frog->A;
            }
        }
        else if(cmd[i]=='B'){
            if(frog->B){
                delfrog(frog);
                frog=frog->B;
            }
        }
        else if(cmd[i]=='C'){
            if(frog->C){
                delfrog(frog);
                frog=frog->C;
            }
        }
        else if(cmd[i]=='D'){
            if(frog->D){
                delfrog(frog);
                frog=frog->D;
            }
        }
    }
    cout << frog->x << " " << frog->y << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    connect();
    jump();
}