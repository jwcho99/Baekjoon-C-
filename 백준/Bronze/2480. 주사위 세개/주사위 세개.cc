#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* int main(){
    int score;
    char grade='?';
    scanf("%d", &score);
    if(90<=score && score<=100) grade = 'A';
    else if(80<=score) grade = 'B';
    else if(70<=score) grade = 'C';
    else if(60<=score) grade = 'D';
    else grade = 'F';
    printf("%c\n", grade);
    return 0;
}
 */

int get_max(int a, int b, int c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }
}

int main(){
    int a,b,c;
    int score=0;
    scanf("%d %d %d", &a, &b, &c);
    if(a==b && b==c) score = 10000+a*1000;
    else if(a==b || a==c) score = 1000+a*100;
    else if(b==c) score = 1000+b*100;
    else score = 100*get_max(a,b,c);

    printf("%d\n", score);
}