//
//  main.c
//  examination_4
//
//  Created by edz on 2020/4/17.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack{
    int elem;
    struct stack *next;
} Stack,Queue;

Stack* init_stack(void);
void free_stack(Stack* head);
int push(Stack* head, int elem);
int pop(Stack* head);
int top(Stack* head);
int is_full(Stack* head);
int is_empty(Stack* head);
void enqueue(Queue* queue, int data); // 函数类型请自己考虑
int dequeue(Queue* queue);


Stack* init_stack(void) {
    Stack* head = malloc(sizeof(Stack));
    head->next = NULL;
    return head;
}

void free_stack(Stack* head) {
    Stack* t;
    while(head->next != NULL) {
        t = head->next;
        free(head);
        head = t;
    }
    free(head);
}

int push(Stack* head, int elem) {
    Stack *new_node = malloc(sizeof(Stack));
    if (new_node == NULL) {
        // 分配内存失败
        return 0;
    }
    new_node->elem = elem;
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}

int pop(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    Stack* t = head->next;
    head->next = t->next;
    int elem = t->elem;
    free(t);
    return elem;
}

int top(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    return head->next->elem;
}

int is_empty(Stack* head) {
    return (head->next == NULL)?1:0;
}
/*
 新建一个栈，利用此栈来暂存先进入的元素，然后等当前元素推入栈后，再将之前的元素推入到当前的栈，从而使得先进入的元素最后在栈顶
 */
void enqueue(Queue* queue, int data){
    //新建一个栈
    Stack* tstack = init_stack();
    //判断当前栈是否为空，不为空时将当前栈元素推入另一个栈
    while(!(is_empty(queue))){
        if(push(tstack, pop(queue)))
            continue;
    }
    //将元素继续推入当前栈
    push(queue, data);
    //当新建的栈不为空时将其元素推入当前栈
    while(!(is_empty(tstack))){
        if(push(queue, pop(tstack)))
            continue;
    }
    //最后得到与原来顺序相反的一个栈
    //return queue;
}

int dequeue(Queue* queue){
    return pop(queue);
}

int main(void) {
    Queue* queue = init_stack();
    int a[5] = {1, 2, 3, 4, 5};
    for( int i = 0; i < 5; i++) {
        enqueue(queue, a[i]);
    }
    
    
    for (int i = 0; i < 5; i++) {
        int out = dequeue(queue);
        printf("%3d", out);
    }
     
    printf("\n");
    return 0;
}
