#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

int board[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int visited[501][501];
int middle[4][3][2]={
    {{0,1},{0,2},{-1,1}},
    {{0,1},{0,2},{1,1}},
    {{1,0},{2,0},{1,1}},
    {{1,0},{2,0},{1,-1}}
};
int ans;
int n,m;

void dfs(int x,int y, int cnt, int total){
    int nx, ny;
    if(cnt==4){
        ans=max(ans, total);
        return;
    }
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(visited[nx][ny]==0){
            visited[nx][ny]=1;
            dfs(nx,ny,cnt+1,total+board[nx][ny]);
            visited[nx][ny]=0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> board[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=1;
            dfs(i,j,1,board[i][j]);
            visited[i][j]=0;
            if(i-1>=0 && j+2<m){
                int sum=board[i][j];
                for(int k=0;k<3;k++){
                    sum+=board[i+middle[0][k][0]][j+middle[0][k][1]];
                }
                ans=max(ans, sum);
            }
            if(i+1<n && j+2<m){
                int sum=board[i][j];
                for(int k=0;k<3;k++){
                    sum+=board[i+middle[1][k][0]][j+middle[1][k][1]];
                }
                ans=max(ans, sum);
            }
            if(i+2<n && j+1<m){
                int sum=board[i][j];
                for(int k=0;k<3;k++){
                    sum+=board[i+middle[2][k][0]][j+middle[2][k][1]];
                }
                ans=max(ans, sum);
            }
            if(i+2<n && j-1>=0){
                int sum=board[i][j];
                for(int k=0;k<3;k++){
                    sum+=board[i+middle[3][k][0]][j+middle[3][k][1]];
                }
                ans=max(ans, sum);
            }
        }
    }
    cout << ans;
}