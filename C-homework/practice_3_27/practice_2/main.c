//
//  main.c
//  practice_2
//
//  Created by edz on 2020/3/27.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
double fact(int n);

// 尽量少的使用乘法运算完成阶乘表的打印

int main(void) {
    for(int i=0; i<=10; i++)
    printf("%d! = %.0f\n", i, fact(i));
    return 0;
}

/*将乘积转化为平方差的乘积，即可减少乘积次数，
 例如 7的阶乘可以看出： 1 * 2 * 3 * 4 * 5 * 6 * 7
 = (4-3) * (4-2) * (4-1) * 4 * (4+1) * (4+2) * (4+3)
 = (4^2-3^2) * (4^2-2^2) * (4^2-1^2) * 4
 = 7 * 12 * 15 * 4
 并且发现各乘积的差为前n个数的奇数差
 */
double fact(int n){
    int i;
    double product = 1;
    int h=n/2, q=h*h;
    if (n <= 1) {
        return product;
    }
    if(n%2 == 0)
        product *= 2*q;
    else
        product *= 2*q*n;
    for (i = 1; i<n-2; i+=2) {
        q -= i;
        product *= q;
    }
    return product;
}

