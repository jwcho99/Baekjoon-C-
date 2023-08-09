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
int cnt[10001]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        cnt[num]+=1;
    }
    for(int i=0;i<10001;i++){
        if(cnt[i]){
            for(int j=0;j<cnt[i];j++) cout << i << "\n";
        }
        else continue;
    }
    
}