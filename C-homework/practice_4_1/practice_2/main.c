//
//  main.c
//  practice_2
//
//  Created by edz on 2020/4/1.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int* smallerNumbersThanCurrent(int* nums, int numsSize);

int main(void) {
    int nums[]={8,1,2,2,3};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int *p;
    p = smallerNumbersThanCurrent(nums, numsSize);
    for(int i=0; i<numsSize; i++)
        printf("%d,", *(p+i));
    printf("\n");
    return 0;
}
int* smallerNumbersThanCurrent(int* nums, int numsSize){
    int* result = (int*)malloc(numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++){
        result[i]=0;
    }
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]>nums[j])
                result[i]++;
            else if(nums[i]<nums[j])
                result[j]++;
            
        }
        
    }
    return result;
}
