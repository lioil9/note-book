//
//  main.c
//  practice_4_1
//
//  Created by edz on 2020/4/1.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target);

int main(void)
{
    int nums[]={2, 7, 11, 15};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int *p;
    p = twoSum(nums, numsSize, 9);
    printf("和为9的两个数下标为：");
    for(int i=0; i<2; i++)
        printf("%d,", *(p+i));
    printf("\n");
}

int* twoSum(int* nums, int numsSize, int target){
    int* result = (int*)malloc(2*sizeof(int)); //定义一个result的int类型的指针变量，申请8个字节的内存空间
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j] == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

