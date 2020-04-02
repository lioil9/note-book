//
//  main.c
//  practice_2
//
//  Created by edz on 2020/4/2.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main(void) {
    int num[]={4,1,2,1,2};
    int numsSize=sizeof(num)/sizeof(num[0]);
    printf("只出现一次的数位：%d\n", singleNumber(num, numsSize));
    
    return 0;
}

/*利用异或的方法可以快速实现对数组中只出现一次的数筛选出来，因为一个数与自身异或后值为0；而与与0异或后为其本身
 由此可见可知，在当转换成二进制数的时候，对各个数值进行异或操作后，数组中相同的数会最后相互抵消掉，而剩下来的数值则就为单独的数，
 所以需要一个中间变量来存储数组第一个元素，然后对之后的数分别异或操作*/
int singleNumber(int* nums, int numsSize){
    int n = nums[0];
    int i;
    for( i = 1; i < numsSize; i++ ){
        n = n ^ nums[i];
    }
    return n;
}

