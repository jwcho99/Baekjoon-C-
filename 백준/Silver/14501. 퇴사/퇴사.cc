#include <bits/stdc++.h>
using namespace std;

#define LL long long
int n;
int t[16],p[16];
int dp[16];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin >> t[i] >> p[i];

    for(int i=n-1;i>=0;i--){
        if(i+t[i]>n) dp[i]=dp[i+1];
        else dp[i]=max(dp[i+t[i]]+p[i],dp[i+1]);
    }
    cout << dp[0] << "\n";
}