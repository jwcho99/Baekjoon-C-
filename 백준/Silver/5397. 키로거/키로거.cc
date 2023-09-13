#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
using namespace std;

typedef struct node{
    char data;
    struct node* prev;
    struct node* next;
}node;

node* head, *tail, *now;

void init(){
    head=(node*)malloc(sizeof(node));
    tail=(node*)malloc(sizeof(node));

    head->prev=head;
    head->next=tail;
    tail->prev=head;
    tail->next=tail;
    now=head;
}


void move(char cmd){
    if(cmd=='<'){
        if(now!=head) now=now->prev;
    }
    else if(cmd=='>'){
        if(now!=tail->prev) now=now->next;
    }
}

void insert(char cmd){
    node* tmp=(node *)malloc(sizeof(node));
    tmp->data=cmd;

    tmp->next=now->next;
    tmp->next->prev=tmp;
    now->next=tmp;
    tmp->prev=now;

    now=now->next;
}

void del(){
    if(now!=head){
        node* tmp=now;
        now=now->prev;
        now->next=tmp->next;
        now->next->prev=now;
        free(tmp);
    }
}

void print_func(){
    node* tmp=head->next;
    while(tmp!=tail){
        cout << tmp->data;
        tmp=tmp->next;
    }
    cout << "\n";
}

void clear(){
    if(head->next!=tail){
        node* tmp=head->next;
        while(tmp!=tail){
            node* del_node=tmp;
            tmp=tmp->next;
            free(del_node);
        }
        head->prev=head;
        head->next=tail;
        tail->prev=head;
        tail->next=tail;
        now=head;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test; cin >> test;
    
    init();

    while(test--){
        string input_cmd; cin >> input_cmd;
        for(int i=0;i<input_cmd.size();i++){
            char c=input_cmd[i];
            if(c=='<' || c=='>') move(c);
            else if(c=='-') del();
            else insert(c);
        }
        print_func();
        clear();
    }

    free(head);
    free(tail);

}