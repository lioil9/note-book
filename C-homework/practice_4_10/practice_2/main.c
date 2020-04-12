//
//  main.c
//  practice_2
//
//  Created by edz on 2020/4/13.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdlib.h>

typedef struct node {
    int data;
    struct node* pNext;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int len;
} RecentCounter;


void enQueue(RecentCounter* queue, int elem);
int deQueue(RecentCounter* queue);
int peek(RecentCounter* queue);
RecentCounter* recentCounterCreate(void);
int recentCounterPing(RecentCounter* obj, int t);
void recentCounterFree(RecentCounter* obj);

RecentCounter* recentCounterCreate() {
    RecentCounter* p = (RecentCounter*)malloc(sizeof(RecentCounter));
    p->head = p->tail = NULL;
    p->len = 0;
    return p;
}

void enQueue(RecentCounter* queue, int elem) {
    Node* pnewNode = (Node*) malloc(sizeof(Node));
    pnewNode->data = elem;
    pnewNode->pNext = NULL;
    if (queue->tail == NULL) {
        queue->tail = pnewNode;
        queue->head = pnewNode;
    } else {
        queue->tail->pNext = pnewNode;
        queue->tail = pnewNode;
    }
    queue->len++;
}

int deQueue(RecentCounter* queue) {
    Node* temp = queue->head;
    queue->head = temp->pNext;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    queue->len--;
    int r = temp->data;
    free(temp);
    return r;
}

int peek(RecentCounter* queue) {
    return queue->head->data;
}

int recentCounterPing(RecentCounter* obj, int t) {
    enQueue(obj, t);
    while( peek(obj) < (t-3000) ) {
        deQueue(obj);
    }
    return obj->len;

    
}

void recentCounterFree(RecentCounter* obj) {
    while(obj->len > 0)
        deQueue(obj);
    free(obj);
}
