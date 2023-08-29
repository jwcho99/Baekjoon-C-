#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long Min, Max; cin >> Min >> Max;
    vector<bool> check(Max-Min+1);

    for(long long i=2;i*i<=Max;i++){
        long long p=i*i;
        long long n=Min/p;
        if(Min%p!=0) n+=1;

        for(long long j=n;p*j<=Max;j++){
            check[(int)((j*p)-Min)]=true;
        }
    }
    int cnt=0;
    for(int i=0;i<Max-Min+1;i++){
            if(!check[i]) cnt+=1;
    }
    cout << cnt << "\n";


}