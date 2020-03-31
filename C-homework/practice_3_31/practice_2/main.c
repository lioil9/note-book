//
//  main.c
//  practice_2
//
//  Created by edz on 2020/3/31.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void printstar(int *b);
void printnum(void);


int main ()
{
    // 生成100个随机数的数组, 分布到0-100
    int i;
    int b[11] = {0};
    
    //生成并打印随机数
    srand((unsigned int)time(NULL));
    int a[100];
    for (i = 0; i < 100; i++) {
        a[i] = rand() % 101;
    }
    for (i = 0; i < 100; ) {
        printf("%4d", a[i]);
        i++;
        if (i%10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    
    //对每个范围内的数据个数进行存储
    for (i = 0; i < 100; i++){
        b[a[i]/10]++ ;
        }
    
    printstar(b);
    printnum();
    return 0;
    
}
/*计算并存储最大个数的星星，即总共有多少行数
打印输出星星，当此列所拥有的星星数大于d值，即打印一个星星，否则打印空格*/
void printstar(int *b){
    int i,j;
    int c=0, d = 0;
    for (i = 0; i <= 10; i++){
        if(i == 6)
            printf("分布图");
        printf("----");
    }
    printf("----\n");
    for (i = 0; i <= 10; i++) {
        if (b[i] > c){
            c = b[i];
            d = b[i];
        }
    }
    for (i = 0; i < c; i++){
        for (j = 0; j <= 10; j++){
            if (b[j]-d >= 0)
                printf("  *  ");
            else
                printf("     ");
        }
        d--;
        putchar('\n');
    }
}
//打印分隔符和数据
void printnum(void){
    for (int i = 0; i <= 10; i++)
        printf("-----");
    putchar('\n');
    for (int i = 0; i <= 10; i++)
        printf("  %d ", i * 10);
    printf("\n");
}

