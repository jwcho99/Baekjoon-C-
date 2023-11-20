#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
// typedef pair<int,int> pii;
typedef long long ll;
#define MAX_N 100001


int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int arr[20];
   for(int i=0;i<20;i++) arr[i]=i+1;

   for(int ii=0;ii<10;ii++){
      int a,b; cin >> a >> b;
      int tmp[20];

      for(int i=a-1;i<b;i++){
         tmp[i]=arr[i];
      }
      for(int i=0;i<b-a+1;i++){
         arr[b-1-i]=tmp[a-1+i];
      }
   }

   for(int i=0;i<20;i++) cout << arr[i] << " ";
}