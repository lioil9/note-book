//
//  main.c
//  practice_3
//
//  Created by edz on 2020/3/27.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //根据输入的月份输出该月的天数，假设该年份不是闰年 怎么用最少的分支结构完成
    // 31天 1,3,5,7, 8,10,12  30天 4,6, 9,11  28天 2
    int month;
    printf("请输入月份：");
    scanf("%d", &month);
    if(month == 2)
        printf("%d有28天。\n", month);
    else if (month==4 || month==6 || month==9 || month==11)
        printf("%d有30天。\n", month);
    else
        printf("%d有31天。\n", month);
    return 0;
}
