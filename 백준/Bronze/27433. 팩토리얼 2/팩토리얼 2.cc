#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ll long long

//  21단계 1번 팩토리얼 2

ll factorial(ll n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main(){
    ll n;
    scanf("%lld", &n);
    printf("%lld", factorial(n));
    return 0;
}

