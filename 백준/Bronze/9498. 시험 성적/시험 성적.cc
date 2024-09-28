#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
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
