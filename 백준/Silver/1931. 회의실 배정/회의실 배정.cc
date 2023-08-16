#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i].second >> arr[i].first;

    sort(arr.begin(), arr.end());

    int start,end;
    start=0, end=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i].second>=end){
            ans+=1;
            end=arr[i].first;
        }
    }
    cout << ans << "\n";
}