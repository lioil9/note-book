//
//  main.c
//  practice_3
//
//  Created by edz on 2020/4/13.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int *queue;
    int head;
    int tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    int i=3000;
    RecentCounter *p = malloc(sizeof(RecentCounter));
    obj->head=0;
    obj->tail=0;
    obj->queue=malloc(3001*sizeof(int));
    while(i>=0) (obj->queue)[i--]=-1;
    return p;
}

int recentCounterPing(RecentCounter* p, int t) {
    while((p->queue)[p->head]<t-3000&&(p->queue)[p->head]!=-1){
        (p->queue)[p->head]=-1;
        if((p->queue)[p->tail]!=-1) p->head++;
        if(p->head>3000) p->head = p->head-3001;
    }
    if((p->queue)[p->tail]!=-1) p->tail++;
    if(p->tail>3000) p->tail = p->tail-3001;
    (p->queue)[p->tail]=t;
    return p->tail>=obj->head?obj->tail-obj->head+1:obj->tail+3002-obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}

