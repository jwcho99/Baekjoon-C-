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

long long a,b;

long long gcd(long long t1, long long t2){
    if(t2==0){
        return t1;
    } 
    else{
        return gcd(t2, t1%t2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    long long ans;
    if(a>=b) ans=gcd(a,b);
    else ans=gcd(b,a);

    for(long long i=0;i<ans;i++){
        cout << "1";
    }
    cout << "\n";
}