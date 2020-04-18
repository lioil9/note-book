//
//  main.c
//  calculator
//
//  Created by edz on 2020/4/18.
//  Copyright © 2020 edz. All rights reserved.
//

#include <stdio.h>
int is_float(char *s);
void calculator(int n);

void calculator(int n){
    char x[10], y[10];
    int a, b;
    double c;
    //while(n !=5){
        printf("请输入第一个操作数：");scanf("%s", x);
        a = is_float(x);
        printf("请输入第二个操作数：");scanf("%s", y);
        b = is_float(y);
        switch (n) {
            case 1:
                printf("%d + %d = %d\n", a, b, a+b);
                break;
            case 2:
                printf("%d - %d = %d\n", a, b, a-b);
                break;
            case 3:
                printf("%d * %d = %.0f\n", a, b, a*b);
                break;
            case 4:
                c = (double)a/b;
                printf("%d / %d = %.2f\n", a, b, c);
                break;
            default:
                break;
        }
    //}
}

int is_float(char *s){
    int x=0;
    while(*s == ' '){
        s++;
    }
    if((*s>='0' && *s<='9')){
            //当开始是数字进入整数部分的转化
        while(*s>='0' && *s<='9'){
                x = 10*x+*s-'0';
                s++;
        }
        if(*s == '.'){
            printf("输入不合法,请重新输入\n");
            return x;
        }
    }else
        printf("输入不合法,请重新输入\n");
    return x;
}

int main(void) {
    int n;
    printf("要进行哪种运算？\n1.加法\n2.减法\n3.乘法\n4.除法\n5.退出\n请输入：");
    scanf("%d", &n);
    while(n!=5){
        calculator(n);
        printf("要进行哪种运算？\n1.加法\n2.减法\n3.乘法\n4.除法\n5.退出\n请输入：");
        scanf("%d", &n);
    }
    
    
    return 0;
}
