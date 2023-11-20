#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
// typedef pair<int,int> pii;
typedef long long ll;
#define MAX_N 100001

ll a,b;

void swap(ll &n1, ll &n2){
   ll tmp=n1;
   n1=n2;
   n2=tmp;
   return;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> a >> b;
   ll cnt;

   if(a>b) swap(a,b);
   cnt=b-a-1;
   if(cnt<=0) cnt=0;
   cout << cnt << "\n";

   for(ll i=a+1;i<b;i++){
      cout << i << " ";
   }
   cout << "\n";
}