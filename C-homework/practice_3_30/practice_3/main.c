//
//  main.c
//  practice_3
//
//  Created by edz on 2020/3/30.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
int max(int a, int b, int c);

int main(int argc, const char * argv[]) {
    int a, b, c;
    printf("请输入要判断的三个数字：\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("最大的数为%d\n", max(a, b, c));
    return 0;
}

//实现计算三个数中最大值的函数
int max(int a, int b, int c){
   //第一种算法,利用if结构判断
    /*
    if(a >= b){
        if(a >= c)
            return a;
        else
            return c;
    }else{
        return b;
    }
    */
    //第二种，利用三目运算符
    int m = (a > b) ? a : b;
    m = (m > c) ? m : c;
    return m;
}
