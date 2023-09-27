#include <bits/stdc++.h>
using namespace std;
#define Size 102

int n,k,l;
int dir=0;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int board[Size][Size]={0};
vector<pair<int,char>> change_time;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for(int i=0;i<k;i++){
        int ax,ay; cin >> ax >> ay;
        board[ax-1][ay-1]=1;
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int ct;
        char cd;
        cin >> ct >> cd;
        change_time.push_back({ct,cd});
    }
    int ans=0;
    int time_index=0;
    board[0][0]=2;
    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    dir=0;
    int x=0, y=0;
    int nx=0, ny=0;
    while(!dq.empty()){
        ans++;
        x=dq.back().first, y=dq.back().second;
        nx=x+dx[dir], ny=y+dy[dir];

        if(0<=nx && nx<n && 0<=ny && ny<n && board[nx][ny]!=2){
            if(board[nx][ny]==0){
                auto [del_x, del_y]=dq.front(); dq.pop_front();
                board[del_x][del_y]=0;
            }
            board[nx][ny]=2;
            dq.push_back({nx,ny});
            
            if(time_index<change_time.size()){
                if(ans==change_time[time_index].first){
                    char change_dir=change_time[time_index].second;
                    time_index++;
                    if(change_dir=='D'){
                        dir=(dir+1)%4;
                    }
                    else if(change_dir=='L'){
                        dir=(dir+3)%4;
                    }
                }
            }
        }
        else break;
    }
    cout << ans << "\n";
}