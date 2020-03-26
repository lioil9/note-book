//
//  main.c
//  practice-1
//
//  Created by edz on 2020/3/26.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //计算两个整数的乘积
    int a, b;
    puts("请输入两个整数。");
    printf("整数1:"); scanf("%d", &a);
    printf("整数2:"); scanf("%d", &b);
    printf("它们的乘积是%d\n", a * b);
    return 0;
}
