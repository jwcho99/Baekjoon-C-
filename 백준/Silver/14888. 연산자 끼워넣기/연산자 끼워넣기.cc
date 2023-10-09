#include <bits/stdc++.h>
using namespace std;

// 덧셈, 뺄셈, 곱셈, 나눗셈

int n;
int oper[4]={0};
int arr[12];
int ans_max=INT_MIN;
int ans_min=INT_MAX;

void dfs(int tmp, int cnt){
    if(cnt==n-1){
        if(tmp>ans_max) ans_max=tmp;
        if(tmp<ans_min) ans_min=tmp;
        return;
    }

    for(int i=0;i<4;i++){
        if(oper[i]>0){
            oper[i]--;
            if(i==0){
                dfs(tmp+arr[cnt+1], cnt+1);
            }
            else if(i==1){
                dfs(tmp-arr[cnt+1], cnt+1);
            }
            else if(i==2){
                dfs(tmp*arr[cnt+1], cnt+1);
            }
            else if(i==3){
                dfs(tmp/arr[cnt+1], cnt+1);
            }
            oper[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<4;i++) cin >> oper[i];


    dfs(arr[0], 0);
    cout << ans_max << "\n" << ans_min << "\n";
}