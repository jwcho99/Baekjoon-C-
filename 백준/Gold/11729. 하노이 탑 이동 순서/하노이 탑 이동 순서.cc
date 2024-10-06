#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ll long long

ll hanoi_cnt(int n){
    if (n == 1) return 1;
    return 2 * hanoi_cnt(n - 1) + 1;
}

void hanoi(int n, int from, int tmp, int to){
    if (n == 1){
        printf("%d %d\n", from, to);
        return;
    }
    hanoi(n - 1, from, to, tmp);
    printf("%d %d\n", from, to);
    hanoi(n - 1, tmp, from, to);

}

int main(){
    int n;
    scanf("%d", &n);

    printf("%lld\n", hanoi_cnt(n));
    hanoi(n, 1, 2, 3);
    return 0;
}
