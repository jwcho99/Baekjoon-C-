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

long n,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    long start=1, end=k;
    long ans=0;
    while(start<=end){
        long mid=(start+end)/2;
        long cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=min(n, mid/i);
        }
        if(cnt<k) start=mid+1;
        else{
            ans=mid;
            end=mid-1;
        }
    }
    cout << ans << "\n";
}