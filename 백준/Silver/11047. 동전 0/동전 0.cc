#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k;
vector<int> arr;


int main(){
    cin >> n >> k;
    arr=vector<int>(n,0);
    for(int i=0;i<n;i++) cin >> arr[i];

    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<=k){
            ans+=k/arr[i];
            k%=arr[i];
        }
    }
    cout << ans << "\n";


}