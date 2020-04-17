//
//  main.c
//  examination_3
//
//  Created by edz on 2020/4/17.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

#define SIZE 20

double my_atof(char *nptr);

double my_atof(char *nptr){
    double s = 0.0;
    double d = 10.0;
    //首先跳过字符串中数字前面的空格字符
    while(*nptr == ' '){
        nptr++;
    }
    //当遇到字符串中的数字和 . 时开始进入转换
    if((*nptr>='0' && *nptr<='9') || *nptr=='.'){
        //当开始是数字进入整数部分的转化
        while(*nptr>='0' && *nptr<='9'){
            s = 10*s+*nptr-'0';
            nptr++;
        }
        //当字符为 . 时开始进行小数部分的转换
        if(*nptr == '.'){
            nptr++;
            while(*nptr>='0' && *nptr<='9'){
                s = s+(*nptr-'0')/d;
                d *= 10;
                nptr++;
            }
        }
        return s;
    }else
        //若遇到非数字和.直接返回s的值，即0
        return s;
}

int main(void) {
    char str[SIZE];
    printf("请输入一段字符串：");
    scanf("%s", str);
    double n=my_atof(str);
    
    printf("转化为数字为 %lf\n", n);
    return 0;
}
