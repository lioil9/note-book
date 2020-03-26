//
//  main.c
//  practice-2
//
//  Created by edz on 2020/3/26.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //计算三个整数的和
    int a, b, c;
    puts("请输入三个整数。");
    printf("整数1:"); scanf("%d", &a);
    printf("整数2:"); scanf("%d", &b);
    printf("整数3:"); scanf("%d", &c);
    printf("它们的和是%d\n", a + b + c);
    return 0;
}
