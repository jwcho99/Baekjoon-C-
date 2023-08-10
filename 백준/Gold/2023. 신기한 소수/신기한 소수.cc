#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int check(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

void dfs(int num, int len){
    if(!check(num)) return;
    if(len==n){
        cout << num << "\n";
        return;
    }
    else{
        dfs(num*10+1,len+1);
        dfs(num*10+3,len+1);
        dfs(num*10+5,len+1);
        dfs(num*10+7,len+1);
        dfs(num*10+9,len+1);
    }

}


int main(){
    cin >> n;
    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}