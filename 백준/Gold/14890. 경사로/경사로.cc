#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,l;
int board[101][101];
int ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> board[i][j];
    }

    int cnt=0;
    bool flag=true;

    for(int i=0;i<n;i++){
        cnt=1;
        flag=true;
        for(int j=0;j<n-1;j++){
            if(!flag) break;
            if(board[i][j]==board[i][j+1]) cnt++;
            else if(board[i][j]==board[i][j+1]-1){
                if(cnt>=l) cnt=1;
                else{
                    flag=false;
                    break;
                }
            }
            else if(board[i][j]==board[i][j+1]+1){
                if(j+1+l-1>=n){
                    flag=false;
                    break;
                }
                for(int k=j+1;k<j+l+1;k++){
                    if(board[i][k]!=board[i][j+1]){
                        flag=false;
                        break;
                    }
                }
                j=j+l-1;
                cnt=0;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }

    for(int j=0;j<n;j++){
        cnt=1;
        flag=true;
        for(int i=0;i<n-1;i++){
            if(!flag) break;
            if(board[i][j]==board[i+1][j]) cnt++;
            else if(board[i][j]==board[i+1][j]-1){
                if(cnt>=l){
                    cnt=1;
                    continue;
                }
                else{
                    flag=false;
                    break;
                }
            }
            else if(board[i][j]==board[i+1][j]+1){
                if(i+1+l-1>=n){
                    flag=false;
                    break;
                }
                for(int k=i+1;k<i+l+1;k++){
                    if(board[k][j]!=board[i+1][j]){
                        flag=false;
                        break;
                    }
                }
                i=i+l-1;
                cnt=0;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout << ans << "\n";
}