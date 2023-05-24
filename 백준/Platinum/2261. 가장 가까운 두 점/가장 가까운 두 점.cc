#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <cstring>
using namespace std; 

vector<pair<int,int>> v;

int n;
vector<pair<int,int>> arr;

int Distance(int from, int to){
    int fromx=arr[from].first, fromy=arr[from].second;
    int tox=arr[to].first, toy=arr[to].second;

    return (fromx-tox)*(fromx-tox)+(fromy-toy)*(fromy-toy);
}

int DivideAndConquer(int from, int to){
    if(from==to) return 10000000;
    if(from+1==to) return Distance(from, to);

    int dis=Distance(from, to);
    int tmp=0, mid=(from+to)/2;

    tmp=DivideAndConquer(from, mid);
    if(tmp<dis) dis=tmp;
    tmp=DivideAndConquer(mid+1, to);
    if(tmp<dis) dis=tmp;

    vector<pair<int,int>> between;
    for(int i=mid;i>=from;i--){
        int nx=arr[i].first;
        if((nx-arr[mid].first)*(nx-arr[mid].first)>dis) break;
        between.push_back({arr[i].second, arr[i].first});
    }
    for(int i=mid+1;i<=to;i++){
        int nx=arr[i].first;
        if((nx-arr[mid].first)*(nx-arr[mid].first)>dis) break;
        between.push_back({arr[i].second, arr[i].first});
    }

    int len=between.size();
    if(len==0) return dis;
    sort(between.begin(), between.end());

    for(int i=0;i<len;i++){
        int ix=between[i].second, iy=between[i].first;
        for(int j=i+1;j<len;j++){
            int jx=between[j].second, jy=between[j].first;
            if(dis<=(jy-iy)*(jy-iy)) break;
            int betweendis=(ix-jx)*(ix-jx)+(iy-jy)*(iy-jy);
            if(betweendis<dis) dis=betweendis;
        }
    }
    return dis;
}

int main(){
    cin >> n;
    arr=vector<pair<int,int>>(n);
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    cout << DivideAndConquer(0,n-1) << "\n";
}