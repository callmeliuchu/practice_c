//
// Created by liuchu on 2020/12/17.
//
#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

#define MAX 100

typedef struct Tree{
    char data;
    struct Tree *left;
    struct Tree *right;
}*BT;

BT create(char *s){
    BT stack[100];
    int top = -1;
    BT head = NULL;
    BT node = NULL;
    int k = -1;
    for(;*s;s++){
        if(*s == '('){
            stack[++top] = node;
            k=1;
        }else if(*s == ')'){
            top--;
        }else if(*s == ','){
            k=2;
        }else{
            node = (BT)malloc(sizeof(struct Tree));
            node->data = *s;
            node->left = NULL;
            node->right = NULL;
            if(head == NULL){
                head = node;
            }
            if(k == 1){
                stack[top]->left = node;
            }
            if(k == 2){
                stack[top]->right = node;
            }
        }
    }
    return head;
}


void print(BT root){
    if(root){
        printf("%c\n",root->data);
        print(root->left);
        print(root->right);
    }
}


void print_parent(BT root,char child){
    BT stack[MAX];
    int stack2[MAX];
    int top = -1;
    BT cur = root;
    while(cur != NULL || top != -1){
        while(cur){
            stack[++top] = cur;
            stack2[top] = 0;
            cur = cur->left;
        }
        int flag = stack2[top];
        BT node = stack[top--];
        if(flag == 0){
            stack[++top] = node;
            stack2[top] = 1;
            cur = node->right;
        }else{
//            printf("%c\n",node->data);
            if(node->data == child){
                for(int i=0;i<=top;i++){
                    printf("%c\n",stack[i]->data);
                }
                return;
            }
            cur = NULL;
        }
    }
}





int main(){
    char s[] = "A(B(I,J(,M)),D(E,F(G,H)))";
    BT root = create(s);
    print(root);
    puts("---------------------");
    print_parent(root,'G');
}