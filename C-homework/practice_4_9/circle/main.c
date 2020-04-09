//
//  main.c
//  practice_4_9
//
//  Created by edz on 2020/4/9.
//  Copyright © 2020 lioil. All rights reserved.
//
//利用数组来解决约瑟夫环


#include<stdio.h>

int main(void){
    int n, k, m;
    printf("输入总人数：");scanf("%d", &n);
    printf("第几个人开始报数：");scanf("%d", &k);
    printf("数到几的人出列：");scanf("%d", &m);
    
    int a[n];
    for(int i=0;i<n;i++){a[i] = 1;}   // 数组初始化，1：表示为未出列；0：表示出列

    int leftCount = n;                // 计数器leftCount：计数剩下的人
    int index = k-1, count = 0;        // 1.数组下标index；2.循环计数器count

    while(leftCount>1){               // 当还剩下一个人结束

        if(a[index] == 1){
            count++;
            
            //计数到m，1.出列；2.循环计数器count重新开始计数；3.计数器leftCount减1
            if(m == count){
                a[index] = 0;
                count = 0;
                leftCount--;
            }
        }
        index++;

        if(index == n){index = 0;}    // 当到数组尾，数组下标index置零，重新开始
    }

    for(int j=0;j<n;j++){             // 输出结果
        if(1 == a[j]){ printf("剩下一个人个人为第%d个\n",j+1); }
    }
}
