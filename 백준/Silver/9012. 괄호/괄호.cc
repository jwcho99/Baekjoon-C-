#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 괄호 확인

typedef struct {
    char data[51];
    int top;
}stack;

void push(stack *s, char c){
    s->data[++(s->top)] = c;
}

bool pop(stack *s){
    if(s->top == -1) return false;
    s->top--;
    return true;
}

int main(){
    int t;
    scanf("%d", &t);

    for(int test_case = 0; test_case < t; test_case++){
        char str[51];
        scanf("%s", str);

        stack s;
        s.top = -1;
        bool flag=true;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == '(') push(&s, str[i]);
            else if(str[i] == ')'){
                if(!pop(&s)){
                    flag = false;
                    break;
                }
            }
        }
        if(s.top != -1) flag = false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}