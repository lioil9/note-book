//
//  main.c
//  practice_4_10
//
//  Created by edz on 2020/4/12.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#define SIZE 10

typedef struct Queue{
    int data[SIZE];
    int top;
    int end;
}Queue;
//队列初始化
Queue *InitQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->top = 0;
    q->end = 0;
    return q;
}
//进入队列并判断是否溢出
void inQueue(Queue *q,int n){
    if((q->end+1)%SIZE == q->top){
        printf("队列溢出\n");
        return;
    }
    q->data[q->end] = n;
    printf("入队元素：%d\n", q->data[q->end]);
    q->end = (q->end+1)%SIZE;
}
//出队列，并判断队列是否为空
void outQueue(Queue *q){
    if(q->top == q->end){
        printf("队列为空\n");
        return ;
    }
    printf("出队元素：%d\n", q->data[q->top]);
    q->top = (q->top+1)%SIZE;
}

int main() {
    Queue *q = InitQueue();

    for (int i = 0; i < 5; i++) {
        inQueue(q, i + 1);
        printf("队头：%d  队尾：%d\n", q->top, q->end);
    }

    for (int i = 0; i <= 5; i++) {
        outQueue(q);
        printf("队头：%d  队尾：%d\n", q->top, q->end);
    }

    return 0;
}
