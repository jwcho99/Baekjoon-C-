#include <bits/stdc++.h>
using namespace std;
#define Size 21

int n=21;
int real_board[Size][Size];
int ans=-1;

void init(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> real_board[i][j];
    }    
}
/*
void make_real(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) real_board[i][j]=copy_board[i][j];
    }
}

void make_copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) copy_board[i][j]=real_board[i][j];
    }
}
*/

void find_max(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) ans=max(ans, real_board[i][j]);
    }
    return;
}

void move_left(){
    deque<int> dq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(real_board[i][j]){
                dq.push_back(real_board[i][j]);
            }
            real_board[i][j]=0;
        }
        int index=0;
        while(!dq.empty()){
            int data=dq.front(); dq.pop_front();
            if(real_board[i][index]==0){
                real_board[i][index]=data;
            }
            else if(real_board[i][index]==data){
                real_board[i][index]*=2;
                index++;
            }
            else{
                index++;
                real_board[i][index]=data;
            }
        }
    }
}
void move_right(){
    deque<int> dq;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(real_board[i][j]){
                dq.push_back(real_board[i][j]);
            }
            real_board[i][j]=0;
        }
        int index=n-1;
        while(!dq.empty()){
            int data=dq.front(); dq.pop_front();
            if(real_board[i][index]==0){
                real_board[i][index]=data;
            }
            else if(real_board[i][index]==data){
                real_board[i][index]*=2;
                index--;
            }
            else{
                index--;
                real_board[i][index]=data;
            }
        }
    }
}
void move_up(){
    deque<int> dq;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(real_board[i][j]){
                dq.push_back(real_board[i][j]);
            }
            real_board[i][j]=0;
        }
        int index=0;
        while(!dq.empty()){
            int data=dq.front(); dq.pop_front();
            if(real_board[index][j]==0){
                real_board[index][j]=data;
            }
            else if(real_board[index][j]==data){
                real_board[index][j]*=2;
                index++;
            }
            else{
                index++;
                real_board[index][j]=data;
            }
        }
    }
}
void move_down(){
    deque<int> dq;
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            if(real_board[i][j]){
                dq.push_back(real_board[i][j]);
            }
            real_board[i][j]=0;
        }
        int index=n-1;
        while(!dq.empty()){
            int data=dq.front(); dq.pop_front();
            if(real_board[index][j]==0){
                real_board[index][j]=data;
            }
            else if(real_board[index][j]==data){
                real_board[index][j]*=2;
                index--;
            }
            else{
                index--;
                real_board[index][j]=data;
            }
        }
    }
}

void dfs(int depth){
    if(depth==5){
        find_max();
        return;
    }
    int copy_board[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            copy_board[i][j]=real_board[i][j];
        }
    }
    move_left();
    dfs(depth+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            real_board[i][j]=copy_board[i][j];
        }
    }

    move_right();
    dfs(depth+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            real_board[i][j]=copy_board[i][j];
        }
    }

    move_up();
    dfs(depth+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            real_board[i][j]=copy_board[i][j];
        }
    }

    move_down();
    dfs(depth+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            real_board[i][j]=copy_board[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();
    dfs(0);
    cout << ans << "\n";
}