//
//  main.c
//  practice_4_2
//
//  Created by edz on 2020/4/2.
//  Copyright © 2020 lioil. All rights reserved.
//
#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char * s);

int main(void) {
    char s[]={"abcabcbb"};
    
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}

int lengthOfLongestSubstring(char * s){
    int max=0,temp=0;
    int i, j, n=0;
    unsigned long len = strlen(s);
    for( i=0; i<len-1; i++){
        for(j=n; j<i; j++){
            if(s[i] == s[j]){
                if(temp>max)max=temp;
                    temp = i-j;
                n = j+1;
                break;
            }
        }
        if(i==j)temp++;
        if(temp>max)max=temp;
    }
    return max;

}
