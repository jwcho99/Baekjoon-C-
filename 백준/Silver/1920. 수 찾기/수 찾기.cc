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

int n,m;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr=vector<int>(n,0);
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cin >> m;
    for(int i=0;i<m;i++){
        int search; cin >> search;
        int start,end;
        start=0, end=n-1;
        bool flag=false;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==search){
                flag=true;
                break;
            }
            if(arr[mid]>search){
                end=mid-1;
            }
            else if(arr[mid]<search){
                start=mid+1;
            }
        }
        if(flag) cout << "1" << "\n";
        else cout << "0" << "\n";
    }
}