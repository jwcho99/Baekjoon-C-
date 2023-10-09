#include <bits/stdc++.h>
using namespace std;

int ans=INT_MAX;
int n;
int arr[21][21];
bool team[22]={false};

void dfs(int cnt, int player){
    if(cnt==n/2){
        vector<int> start, link;
        int start_score=0, link_score=0;
        for(int i=0;i<n;i++){
            if(team[i]) start.push_back(i);
            else link.push_back(i);
        }
        for(int i=0;i<(n/2)-1;i++){
            for(int j=i+1;j<n/2;j++){
                start_score+=(arr[start[i]][start[j]]+arr[start[j]][start[i]]);
                link_score+=(arr[link[i]][link[j]]+arr[link[j]][link[i]]);
            }
        }
        ans=min(ans, abs(start_score-link_score));
        return;
    }

    for(int i=player;i<n;i++){
        if(team[i]) continue;
        else{
            team[i]=true;
            dfs(cnt+1, i);
            team[i]=false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> arr[i][j];
    }

    dfs(0,0);

    cout << ans << "\n";
    
}