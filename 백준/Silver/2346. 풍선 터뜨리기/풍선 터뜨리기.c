#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct node{
    int data;
    int idx;
    struct node* next;
    struct node* prev;
}node;

typedef struct{
    node* head;
    node* tail;
    int size;
}deque;

void init_dq(deque* dq){
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;
}

bool is_empty(deque* dq){
    return dq->size == 0;
}

void push_front(deque* dq, int data, int idx){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->idx = idx;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(is_empty(dq)){
        dq->head = new_node;
        dq->tail = new_node;
    }
    else{
        new_node->next = dq->head;
        dq->head->prev = new_node;
        dq->head = new_node;
    }
    dq->size++;
}

void push_back(deque* dq, int data, int idx){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->idx = idx;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(is_empty(dq)){
        dq->head = new_node;
        dq->tail = new_node;
    }
    else{
        new_node->prev=dq->tail;
        dq->tail->next = new_node;
        dq->tail = new_node;
    }
    dq->size++;
}

node pop_front(deque* dq){
    if(is_empty(dq)){
        node empty_node;
        empty_node.data = -1;
        empty_node.idx = -1;
        empty_node.next = NULL;
        empty_node.prev = NULL;
        return empty_node;
    }
    else{
        node* temp = dq->head;
        node ret_node;
        ret_node.data = temp->data;
        ret_node.idx = temp->idx;
        ret_node.next = NULL;
        ret_node.prev = NULL;

        dq->head = dq->head->next;
        free(temp);
        dq->size--;
        return ret_node;
    }
}

node pop_back(deque* dq){
    if(is_empty(dq)){
        node empty_node = {-1, -1, NULL, NULL};
        return empty_node;
    }
    else {
        node* tmp = dq->tail;
        node ret_node = {tmp->data, tmp->idx, NULL, NULL};
        dq->tail = dq->tail->prev;
        free(tmp);
        dq->size--;
        return ret_node;
    }
}





int main(){
    int n;
    scanf("%d", &n);

    deque dq;
    init_dq(&dq);

    for(int i=0;i<n;i++){
        int num;
        scanf("%d", &num);
        push_back(&dq, num, i+1);
    }

    while(!is_empty(&dq)){
        node tmp = pop_front(&dq);
        printf("%d ", tmp.idx);
        if(tmp.data>0){
            while(!is_empty(&dq) && tmp.data>1){
                node tmp2 = pop_front(&dq);
                push_back(&dq, tmp2.data, tmp2.idx);
                tmp.data--;
            }
        }
        else {
            while(!is_empty(&dq) && tmp.data<0){
                node tmp2 = pop_back(&dq);
                push_front(&dq, tmp2.data, tmp2.idx);
                tmp.data++;
            }
        }
    }

}