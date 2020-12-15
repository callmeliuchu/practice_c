//
// Created by 刘楚 on 2020/11/21.
//
#include "stdio.h"
#include "stdlib.h"
#define MAX 20

typedef  struct Node{
    char data;
    Node *left;
    Node *right;
}Node;


Node *create(char *s){
    Node *stack[MAX];
    int k = 0;
    int top = -1;
    Node *cur = NULL;
    Node *head = NULL;
    while(*s){
        if(*s == '('){
            stack[++top] = cur;
            k = 1;
        }else if(*s == ')'){
            top--;
        }else if(*s == ','){
            k = 2;
        }else{
            cur = (Node *)malloc(sizeof(Node));
            cur->data = *s;
            cur->left = NULL;
            cur->right = NULL;
            if(head == NULL){
                head = cur;
            }
            if(k == 1){
                stack[top]->left = cur;
            }
            if(k == 2){
                stack[top]->right = cur;
            }
        }
        s++;
    }
    return head;
}


void printlr(Node *root){
    if(root){
        printf("%c\n",root->data);
        printlr(root->left);
        printlr(root->right);
    }
}


void find_parent(Node *root,char item){
    Node *stack[MAX];
    int top=-1;
    int result[MAX];

    Node *cur=root;
    while(cur != NULL || top != -1){
        while(cur != NULL){
            stack[++top] = cur;
            result[top] = 0;
            cur = cur->left;
        }
        int flag = result[top];
        cur = stack[top--];
        if(flag == 0){
            stack[++top] = cur;
            result[top] = 1;
            cur = cur->right;
        }else{
            printf("%c\n",cur->data);
            if(cur->data == item){
                printf("------------");
                for(int i=0;i<=top;i++){
                    printf("%c\n",stack[i]->data);
                }
                break;
            }
            cur = NULL;
        }


    }
}




int main(){
    char s[] = "A(B,C(D,E(F(G(H,I(J,K(M)))))))";
    Node *root = create(s);
    find_parent(root,'M');
}