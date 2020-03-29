//
//  main.c
//  practice_4
//
//  Created by edz on 2020/3/27.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
     输入10个字符，统计其中的英文字母、数字字符和其他字符的个数。
     */
    int letter, digit, other, i;
    char ch;
    letter = 0;
    digit = 0;
    other = 0;
    printf("请输入10个字符：");
    for (i = 0; i<=10; i++) {
        scanf("%c",&ch);
        if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))
            letter++;
        else if(ch>='0'&&ch<='9')
            digit++;
        else
            other++;
    }
    printf("其中英文字母，数字，其他字符个数分别为:%d,%d,%d\n", letter, digit, other);
    return 0;
}
