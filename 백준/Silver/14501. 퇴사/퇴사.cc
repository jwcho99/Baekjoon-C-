#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int map[20][2];
int pay[20];
int ans;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> map[i][0] >> map[i][1];
    }
    int to_date;
    for(int i=n;i>0;i--){
        to_date=i+map[i][0];
        if(to_date>n+1) pay[i]=pay[i+1];
        else pay[i]=max(pay[i+1], map[i][1]+pay[to_date]);
    }
    cout << pay[1] << "\n";
}