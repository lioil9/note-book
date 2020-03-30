//
//  main.c
//  practice_3_30
//
//  Created by edz on 2020/3/30.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
double cuboid(double length, double width, double height);

int main(void) {
    double l, w, h;
    printf("请输入分别长方体的长宽高：\n");
    scanf("%lf%lf%lf", &l, &w, &h);
    
    printf("长方体的体积为：%.0lf\n", cuboid(l, w, h));
    return 0;
}

// 实现计算长方体体积的函数
double cuboid(double length, double width, double height){
    double v;
    v = length * width * height;
    return v;
}
