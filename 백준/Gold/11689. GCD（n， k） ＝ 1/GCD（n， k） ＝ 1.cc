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

long long n;

long long fun(){
    long long ans=n;
    long long sqrtn=sqrt(n);
    for(long long i=2;i<=sqrtn;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n!=1){
        ans=ans/n*(n-1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    long long answer=fun();
    cout << answer << "\n";

}