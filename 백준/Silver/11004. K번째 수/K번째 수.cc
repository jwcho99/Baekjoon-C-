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

int n,k;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    arr=vector<int>(n,0);
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << arr[k-1];
    
}