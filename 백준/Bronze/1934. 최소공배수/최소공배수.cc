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

int test, a, b;

int gcd(int t1, int t2){
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

    cin >> test;

    for(int i=0;i<test;i++){
        cin >> a >> b;
        int ans;
        if(a>=b){
            ans=a*b/gcd(a,b);
        }
        else ans=a*b/gcd(b,a);

        cout << ans << "\n";
    }

}