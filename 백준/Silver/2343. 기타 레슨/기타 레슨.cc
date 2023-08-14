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

    cin >> n >> m;
    arr=vector<int>(n,0);
    int start=0, end=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        start=max(arr[i], start);
        end+=arr[i];
    }

    while(start<=end){
        int mid=(start+end)/2;
        int sum=0;
        int count=0;

        for(int i=0;i<n;i++){
            if(sum+arr[i]>mid){
                count+=1;
                sum=0;
            }
            sum+=arr[i];
        }
        if(sum!=0) count+=1;
        if(count>m) start=mid+1;
        else end=mid-1;
    }
    cout << start << "\n";

}