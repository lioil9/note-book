//
//  main.c
//  examination_2
//
//  Created by edz on 2020/4/17.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

void draw(unsigned int n); // n > 0

void draw(unsigned int n){
    //定义一个二维数组；且数组行数大于要打印的行数
    int a[n][n];
    //先将每行数列的头和尾部赋值为行数
    for(int i=0; i<n; i++)
        a[i][0]=a[i][i]=i+1;
    //每行第二个元素开始的值为其上一行和上一行前一个元素的和
    for(int i=2; i<n; i++){
        for(int j=1; j<i; j++)
            a[i][j] = a[i-1][j-1]+a[i-1][j];
    }
    
    //将数列按照三角形进行打印
    for(int i=0; i<n; i++){
        for(int j=0; j<= n-i; j++)
            printf("  ");
        for(int k=0; k<=i; k++)
            printf("%4d", a[i][k]);
        
        printf("\n");
    }
    
    
}

int main(void) {
    int n;
    printf("请输入行数：");
    scanf("%d", &n);
    if(n>0)
        draw(n);
    else
        printf("请输入一个大于0的行数\n");
    return 0;
}
