//
//  main.c
//  practice_4_3
//
//  Created by edz on 2020/4/6.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

void hanoi(int,char,char,char);
static int k=0;

int main ()
{
    int n;
    printf("输入汉诺塔的块数：");
    scanf("%d",&n);
    printf("\n");
    hanoi(n,'A','B','C');
    printf("一共移动了%d次\n", k);
    return 0;
}

void hanoi(int n, char A, char B, char C){
    k++;
    if(n==1)
        printf(" %c --> %c\n", A, B);
    else{
        hanoi(n-1, A, C, B);
        printf(" %c --> %c\n", A, B);
        hanoi(n-1, C, B, A);
    }
}
