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

bool peli(int target){
    string str=to_string(target);
    for(int i=0, j=str.size()-1;i<j,j>=0;i++,j--){
        if(str[i]!=str[j]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool* check = new bool[MAX];
    fill(check, check + MAX, true);
    check[0] = check[1] = false;

    for(ll i = 2; i < MAX; i++) {
        if(check[i]) {
            for(ll j = 2; i * j < MAX; j++) {
                check[i*j] = false; 
            }
        }
    }
    int n; cin >> n;
    for(int i=n;i<MAX;i++){
        if(check[i]&&peli(i)){
            cout << i << "\n";
            break;
        }
    }
    delete[] check;   

}