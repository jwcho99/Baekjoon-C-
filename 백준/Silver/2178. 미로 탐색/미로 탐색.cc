#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int map[101][101]={};
int visited[101][101]={};
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    queue<pair<int,int>> q;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        int x,y,nx,ny;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            nx=x+dx[i];
            ny=y+dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (map[nx][ny]==0 || visited[nx][ny]!=0) continue;

            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
        }

    }
    cout << visited[n-1][m-1] << "\n";
}