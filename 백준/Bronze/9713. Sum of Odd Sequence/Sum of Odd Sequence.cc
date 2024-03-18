#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int cmd; cin >> cmd;
        int total=0;
        for(int j=1;j<=cmd;j+=2) total+=j;

        cout << total << "\n";
    }
}