#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> belt;
vector<int> robot;
int n,k;

void rotate();
void move();
int count();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    belt = vector<int>(2*n,0);
    robot = vector<int>(2*n,0);

    for(int i=0;i<2*n;i++) cin >> belt[i];
    int stage=1;
    while(true){
        rotate();
        move();
        if(belt[0]>0){
            robot[0]=1;
            belt[0]-=1;
        }
        int cnt=count();
        if(cnt>=k) break;
        stage+=1;
    }
    cout << stage << "\n";
}

void rotate(){
    int tmp=belt[2*n-1];
    for(int i=2*n-1;i>0;i--) belt[i]=belt[i-1];
    belt[0]=tmp;

    for(int i=n-2;i>0;i--) robot[i]=robot[i-1];
    robot[0]=0;
    robot[n-1]=0;
}

void move(){
    for(int i=n-2;i>=0;i--){
        if(robot[i] && robot[i+1]==0 && belt[i+1]>0){
            robot[i]=0;
            robot[i+1]=1;
            belt[i+1]-=1;
        } 
    }
    if(robot[n-1]) robot[n-1]=0;
}

int count(){
    int c=0;
    for(int i=0;i<2*n;i++){
        if(belt[i]==0) c+=1;
    }
    return c;
}