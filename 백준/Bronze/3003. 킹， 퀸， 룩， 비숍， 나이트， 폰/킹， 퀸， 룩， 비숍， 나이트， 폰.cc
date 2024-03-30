#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   int real[6]={1,1,2,2,2,8};
   int num[6];

   for(int i=0;i<6;i++) cin >> num[i];

   for(int i=0;i<6;i++) printf("%d ", real[i]-num[i]);
}