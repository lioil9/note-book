//
//  main.c
//  practice_2
//
//  Created by edz on 2020/3/30.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
int fib(int n);

int main(void) {
    int n;
    printf("请输入要计算的斐波那契数列项数：");
    scanf("%d", &n);
    printf("第%d斐波那契数为%d\n", n, fib(n));
    return 0;
}

//实现计算第n项斐波拉契数列的函数(n >= 0)
int fib(int n){
    int x = 0, x1 = 1, x2 = 1, i;
    if(n==1 || n==2)
        return 1;
    else{
        for( i=3; i<=n; i++ ){
            x = x1 + x2;
            x1 = x2;
            x2 = x;
        }
        return x;
    }
}
