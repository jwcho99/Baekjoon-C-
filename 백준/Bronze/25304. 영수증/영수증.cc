#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int x,n;
    scanf("%d %d", &x, &n);
    int a,b;
    int total=0;
    for(int i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        total+=a*b;
    }
    if(total==x) printf("Yes\n");
    else printf("No\n");

    return 0;
}