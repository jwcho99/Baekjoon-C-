#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> maze;
vector<vector<int>> visited;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    maze=vector<vector<int>>(n,vector<int>(m,0));
    visited=vector<vector<int>>(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            maze[i][j]=s[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(maze[nx][ny]==1 && !visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=visited[x][y]+1;
                }
            }
        }
    }
    cout << visited[n-1][m-1] << "\n";
}
