#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    vector<int> arr(n+1, 0);

    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            for(int j=i;j<=n;j+=i){
                arr[j]=max(arr[j],i);
            }
        }
    }   
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i]<=k) ans+=1;
    } 
    cout << ans << "\n";
}