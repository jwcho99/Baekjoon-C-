#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct node{
    int data;
    int idx;
    struct node* next;
}node;

typedef struct{
    int size;
    node* top;
}stack;

void initstack(stack* s){
    s->size = 0;
    s->top = NULL;
}

bool isempty(stack* s){
    return s->size == 0;
}

void push(stack* s, int data, int idx){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->idx = idx;
    newnode->next = s->top;
    s->top = newnode;
    s->size++;
}

node pop(stack* s){
    if(isempty(s)){
        printf("stack is empty\n");
        exit(1);
    }
    node ret = {s->top->data,s->top->idx,NULL};
    node* tmp= s->top;
    s->top = tmp->next;
    free(tmp);
    s->size--;
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);

    stack s;
    initstack(&s);

    int* num = (int*)malloc(sizeof(int) * n);
    int* res = (int*)malloc(sizeof(int) * n);

    for(int i=0;i<n;i++){
        scanf("%d", &num[i]);
        res[i]=-1;

        while(!isempty(&s) && s.top->data < num[i]){
            node pop_node = pop(&s);
            res[pop_node.idx] = num[i];
        }
        push(&s, num[i], i);
    }

    for(int i=0;i<n;i++){
        printf("%d ", res[i]);
    }
    free(num);
    free(res);

    return 0;
}