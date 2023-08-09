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

void mergesort(int s, int e);
vector<int> arr;
vector<int> tmp;
int n;
long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr=vector<int>(n,0);
    tmp=vector<int>(n,0);

    for(int i=0;i<n;i++) cin >> arr[i];
    ans=0;
    mergesort(0,n-1);
    cout << ans << "\n";
}

void mergesort(int s, int e){
    if(e-s<1) return;

    int mid=(s+e)/2;
    mergesort(s,mid);
    mergesort(mid+1,e);

    for(int i=s;i<=e;i++) tmp[i]=arr[i];

    int insert=s;
    int i1=s;
    int i2=mid+1;

    while(i1<=mid && i2<=e){
        if(tmp[i1]>tmp[i2]){
            arr[insert]=tmp[i2];
            ans+=i2-insert;
            insert+=1;
            i2+=1;
        }
        else{
            arr[insert]=tmp[i1];
            insert+=1;
            i1+=1;
        }
    }

    while(i1<=mid){
        arr[insert]=tmp[i1];
        insert+=1;
        i1+=1;
    }
    while(i2<=e){
        arr[insert]=tmp[i2];
        insert+=1;
        i2+=1;
    }
}