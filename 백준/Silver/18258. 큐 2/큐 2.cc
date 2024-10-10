#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 괄호 확인

/* typedef struct {
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
} */

// 큐2

typedef struct{
    int data[2000002];
    int front;
    int rear;

}queue;

void initqueue(queue *q){
    q->front = 0;
    q->rear = 0;
}

void push(queue *q, int x){
    q->data[q->rear++] = x;
}

void pop(queue *q){
    if(q->front == q->rear) printf("-1\n");
    else printf("%d\n", q->data[q->front++]);
}

void size(queue *q){
    printf("%d\n", q->rear - q->front);
}

void front(queue *q){
    if(q->front == q->rear) printf("-1\n");
    else printf("%d\n", q->data[q->front]);
}

void back(queue *q){
    if(q->front == q->rear) printf("-1\n");
    else printf("%d\n", q->data[q->rear - 1]);
}

void empty(queue *q){
    if(q->front == q->rear) printf("1\n");
    else printf("0\n");
}

int n;
queue q;

int main(){
    scanf("%d", &n);
    initqueue(&q);
    for(int i=0;i<n;i++){
        char str[6];
        scanf("%s", str);
        if(str[0] == 'p' && str[1] == 'u'){
            int x;
            scanf("%d", &x);
            push(&q, x);
        }
        else if(str[0] == 'p' && str[1] == 'o') pop(&q);
        else if(str[0] == 's') size(&q);
        else if(str[0] == 'f') front(&q);
        else if(str[0] == 'b') back(&q);
        else if(str[0] == 'e') empty(&q);
    }
    return 0;
}