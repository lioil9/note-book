//
//  main.c
//  test2
//
//  Created by edz on 2020/3/27.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <math.h>
//最少的步骤完成素数运算
//以取模运算最少作为标准
/*这里我将要进行判断的数进行开平方，因为因数都是成对出现的，
 并且每个数的因数其中一个数必然小于等于这个数的开平方，另一个大于等于这个数的开平方。
 */
int main(void) {
    int i, m;
    printf("请输入要判断的数：");
    scanf("%d", &m);
    for(i=2; i<=sqrt(m); i++){
        if (m%i == 0){
            printf("不是素数\n");
            break;
        }
    }
    if(i > sqrt(m))
        printf("是素数\n");
    return 0;
}
