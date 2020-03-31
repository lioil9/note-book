//
//  main.c
//  practice_3_31
//
//  Created by edz on 2020/3/31.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
//将大小写字母进行转换

int main(void)
{
    char c;
    while((c = getchar()) != EOF){
        if(c >= 'A' && c <= 'Z'){
            c += ('a' - 'A');
            printf("%c", c );
        }
        else if(c >= 'a' && c <= 'z'){
            c -= ('a' - 'A');
            printf("%c", c);
        }
    }
    return 0;
}
