#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x,y;
    int day;
}queue;


int main() {
    int n,m;
    int **map;
    int **visit;
    int **day;
    int front = 0;
    int rear = 0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    queue *q;
    queue *tmp;
    int i,j;
    int nx,ny;
    int max = 0;
    int cnt = 0;
    int flag = 0;

    scanf("%d %d",&m,&n);

    map = (int**)malloc(sizeof(int*)*n);
    visit = (int**)malloc(sizeof(int*)*n);
    day = (int**)malloc(sizeof(int*)*n);
    q = (queue*)malloc(sizeof(queue)*n*m);

    for(i=0;i<n;i++){
        map[i] = (int*)malloc(sizeof(int)*m);
        visit[i] = (int*)malloc(sizeof(int)*m);
        day[i] = (int*)malloc(sizeof(int)*m);
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            visit[i][j] = 0;
            day[i][j] = 0;
            if(map[i][j] == 1){
                q[rear].x = i;
                q[rear].y = j;
                q[rear].day = 0;
                rear++;
            }
        }
    }

    while(front < rear){
        tmp = &q[front];
        front++;
        for(i=0;i<4;i++){
            nx = tmp->x + dx[i];
            ny = tmp->y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(map[nx][ny] == 0 && visit[nx][ny] == 0){
                    visit[nx][ny] = 1;
                    day[nx][ny] = tmp->day + 1;
                    q[rear].x = nx;
                    q[rear].y = ny;
                    q[rear].day = tmp->day + 1;
                    rear++;
                }
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j] == 0 && visit[i][j] == 0){
                flag = 1;
                break;
            }
            if(max < day[i][j]){
                max = day[i][j];
            }
        }
    }

    if(flag == 1){
        printf("-1\n");

    }
    else{
        printf("%d\n",max);
    }
    
}