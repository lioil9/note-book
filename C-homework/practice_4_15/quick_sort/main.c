//
//  main.c
//  quick_sort
//
//  Created by edz on 2020/4/16.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void quick_sort(int a[], int l, int r);
void print_sort(int a[]);

void quick_sort(int a[], int l, int r){
    int base = a[l];
    int i=l, j=r;
    //当左下标大于右下标时，结束
    if(l>r) return;
    while(i != j){
        //当左指针下标小于右指针下标并且右指针其值大于参照数时，右指针继续向左移动
        while(i<j && a[j]>=base) j--;
        //循环结束时右指针找到比参照数小的数，将其值赋给左指针指向的数
        if(j>i) a[i]=a[j];
        while(i<j && a[i]<=base) i++;
        //循环结束时右指针找到比参照数小的数，将其值赋给左指针指向的数
        if(i<j) a[j]=a[i];
    }
    a[i]=base;
    quick_sort(a,l,i-1);/*递归左边*/
    quick_sort(a,i+1,r);/*递归右边*/
}

void print_sort(int a[]){
    for(int i=0; i<SIZE; i++){
        printf("%4d", a[i]);
    }
    
}

int main(void){
    int a[SIZE];
    srand((unsigned int)time(NULL));
    for(int i=0; i<SIZE; i++) a[i]=rand()%100;
    print_sort(a);
    printf("\n");
    
    quick_sort(a, 0, SIZE-1);
    print_sort(a);
    printf("\n");
    
    return 0;
}
