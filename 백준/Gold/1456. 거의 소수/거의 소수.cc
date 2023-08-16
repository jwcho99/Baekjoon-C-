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
using ll = long long;
ll MAX = 10000001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<ll> prime;
    bool* check = new bool[MAX];
    fill(check, check + MAX, true);
    check[0] = check[1] = false;

    for(ll i = 2; i < MAX; i++) {
        if(check[i]) {
            prime.push_back(i);
            for(ll j = 2; i * j < MAX; j++) {
                check[i*j] = false; 
            }
        }
    }
    delete[] check;
    ll a, b;
    ll temp;
    int cnt = 0;

    cin >> a >> b;
    for(ll x : prime) {
        temp = x;
        while(temp <= b / x){
            temp *= x;
            if (temp >= a) cnt++;
        }
    }
    cout << cnt;

}