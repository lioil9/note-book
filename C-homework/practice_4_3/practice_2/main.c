//
//  main.c
//  practice_2
//
//  Created by edz on 2020/4/6.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int* constructArray(int n, int k);

int main(int argc, const char * argv[]) {
    int n,k;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    int *p;
    p = constructArray(n, k);
    for(int i=0; i<n; i++)
        printf("%d,", *(p+i));
    printf("\n");
    return 0;
}

/*当 k=n-1 时，有效的构造是 [1, n, 2, n-1, 3, n-2, ....]。
  当 k=1 时，有效的构造是 [1, 2, 3, ..., n]
  将两个结合起来，前面部分为n-k-1个顺序序列， 后面有 k+1 个元素按照 即有k=n-1排列，最后再加上 n-k-1，将两部分构造结合
 */
int* constructArray(int n, int k){
    int* res = malloc( n * sizeof(int));
    // 首先构造 n-k-1 前面部分的序列
    for(int i = 1;i < n - k;i++){
        res[i-1] = i;
    }
    int a = 1;
    int b = k+1;
    /* 后面的构造部分，也有两部分构成，当数组索引能被2整除时，按照顺序递增；不能被2整除，按照n递减；并且最后都要加上n-k-1
     */
    for(int i = n-k-1;i < n;i++){
        if((i-n-k-1) % 2 == 0){
            res[i] = a++;
            res[i] += n-k-1;
        }else{
            res[i] = b--;
            res[i] += n-k-1;
        }
    }
    return res;
}
