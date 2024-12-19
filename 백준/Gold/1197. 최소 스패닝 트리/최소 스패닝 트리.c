#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct edge{
    int start, end, weight;
}edge;

int compare(const void* a, const void* b){
    edge* aa=(edge*)a;
    edge* bb=(edge*)b;
    return aa->weight-bb->weight;
}// 오름차순 정렬

int parent[MAX];
edge edges[MAX];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void union_find(int x, int y){
    x=find(x);
    y=find(y);
    if(x!=y) parent[x]=y;
}

int main(){
    int v,e;
    scanf("%d %d", &v, &e);

    for(int i=0;i<e;i++){
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);
    }

    for(int i=1;i<=v;i++) parent[i]=i;

    qsort(edges, e, sizeof(edge), compare);

    int ans=0;
    int cnt=0;
    for(int i=0;cnt<v-1;i++){
        if(find(edges[i].start)!=find(edges[i].end)){
            union_find(edges[i].start, edges[i].end);
            ans+=edges[i].weight;
            cnt++;
        }
    }
    printf("%d\n", ans);
    return 0;

}