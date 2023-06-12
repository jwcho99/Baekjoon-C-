#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string a,b;
int dp[1001][1001];
vector<char> ans;

void get_ans(int x, int y);

int main(){
    cin >> a >> b;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[a.size()][b.size()] << "\n";

    get_ans(a.size(), b.size());
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
    cout << "\n";
}

void get_ans(int x, int y){
    if(x==0 || y==0) return;
    if(a[x-1]==b[y-1]){
        ans.push_back(a[x-1]);
        get_ans(x-1,y-1);
    }
    else{
        if(dp[x][y-1]>dp[x-1][y]) get_ans(x,y-1);
        else get_ans(x-1,y);
    }
}