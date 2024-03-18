#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
ll dist[110][110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=987654321;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        if(dist[a][b]>c) dist[a][b]=c;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==987654321) dist[i][j]=0;
            printf("%ld ", dist[i][j]);
        }
        printf("\n");
    }
}