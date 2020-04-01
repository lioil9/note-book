//
//  main.c
//  practice_3
//
//  Created by edz on 2020/4/1.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int lengthOfLongestSubstring(char * s);

int main(void) {
    char s[]={"abcabcbb"};
    
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}

int lengthOfLongestSubstring(char * s){
    int max=1,temp=1;
    int i, j, n=0;
    int len = sizeof(s)/sizeof(s[0]);
    for( i=1; i<len-1; i++){
        for(j=n; j<i; j++){
            if(s[i] == s[j]){
                if(temp>max)max=temp;
                    temp = i-j;
                n = j+1;
                break;
            }
        }
        if(temp>max)max=temp;
    }
    return max;

}

