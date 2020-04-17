//
//  main.c
//  examination_4_17
//
//  Created by edz on 2020/4/17.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int calc_spaces(int n);

//得到公式为 L(n) = 1+(1+n)n/2 (n>=0)
int calc_spaces(int n){
    int sp;
    if(n<0)
        return 0;
    else {
        sp = 1+(1+n)*n/2;
        return sp;
    }
}

int main(void) {
    int n, sp;
    printf("请输入多少条直线：");
    scanf("%d", &n);
    sp = calc_spaces(n);
    if(sp)
        printf("%d条直线可以划分出%d个空间\n", n, sp);
    else
        printf("输入的直线数量必须不小于0\n");
    
    return 0;
}
