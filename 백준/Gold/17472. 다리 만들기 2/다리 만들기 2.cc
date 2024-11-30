#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int board[11][11];
int map[11][11];
bool visited[11][11];
int parent[10];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

typedef struct node {
    int x,y;
    int dist;
}node;

bool cmp(node a, node b){
    return a.dist<b.dist;
}

vector<node> nv;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void uni(int x, int y){
    x=find(x);
    y=find(y);
    if(x!=y) parent[x]=y;
}

void numbering(int x, int y, int num){
    queue<pair<int,int>> q;
    visited[x][y]=true;
    map[x][y]=num;
    q.push({x,y});

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny]==1 && !visited[nx][ny]){
                visited[nx][ny]=true;
                map[nx][ny]=num;
                q.push({nx,ny});
            }
        }
    }
}

void make_bridge(int x, int y, int dir){
    int nx=x, ny=y;
    int dist=0;
    int number=map[x][y];

    while(true){
        nx+=dx[dir];
        ny+=dy[dir];
        if(nx<0 || nx>=n || ny<0 || ny>=m || map[nx][ny]==number) return;
        if(map[nx][ny]==0) dist++;
        else{
            if(dist>=2){
                nv.push_back({number,map[nx][ny],dist});
            }
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> board[i][j];
    }
    // cout << "stage-1\n";
    memset(visited, false, sizeof(visited));
    
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1 && !visited[i][j]){
                numbering(i,j,++num);
            }
        }
    }
    // cout << "stage0\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]!=0){
                for(int k=0;k<4;k++){
                    make_bridge(i,j,k);
                }
            }
        }
    }
    sort(nv.begin(), nv.end(), cmp);

    for(int i=1;i<=num;i++) parent[i]=i;

    // cout << "stage1\n";
    int ans=0;
    for(int i=0;i<nv.size();i++){
        if(find(nv[i].x)!=find(nv[i].y)){
            uni(nv[i].x, nv[i].y);
            // cout << nv[i].x << " " << nv[i].y << " " << nv[i].dist << "\n";
            ans+=nv[i].dist;
        }
    }

    // cout << "stage2\n";
    int tmp_p=find(1);
    for(int i=2;i<=num;i++){
        if(find(i)!=tmp_p){
            ans=-1;
            break;
        }
    }
    // cout << "stage3\n";

    cout << ans << "\n";


}
