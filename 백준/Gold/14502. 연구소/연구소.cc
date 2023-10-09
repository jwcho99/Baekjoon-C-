#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int map[8][8];
int copy_map[8][8];
int visited[8][8];
queue<pair<int,int>> virus;
queue<pair<int,int>> copy_virus;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans;

void copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            copy_map[i][j]=map[i][j];
        }
    }
}
void bfs(){
    int count=0;
    copy_virus=virus;
    memset(visited,0,sizeof(visited));
    while(!copy_virus.empty()){
        int x,y;
        x=copy_virus.front().first;
        y=copy_virus.front().second;
        copy_virus.pop();
        visited[x][y]=1;
        for(int i=0;i<4;i++){
            int nx,ny;
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(copy_map[nx][ny]==0 && !visited[nx][ny]){
                copy_map[nx][ny]=2;
                copy_virus.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(copy_map[i][j]==0){
                count+=1;
            }
        }
    }
    ans=max(ans, count);
}

void dfs(int cnt){
    if(cnt==3){
        copy();
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                map[i][j]=1;
                dfs(cnt+1);
                map[i][j]=0;
            }
        }
    }
}



int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j]==2) virus.push({i,j});
        }
    }
    dfs(0);
    cout << ans;


}