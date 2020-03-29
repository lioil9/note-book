//
//  main.c
//  practice_3_27
//
//  Created by edz on 2020/3/27.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
//打印所示温度转换表。

int main(void) {
    int celsius, fahr;
    //c = 5(f - 32) / 9
    printf("   F       C\n");
    for(fahr = 40; fahr <= 300; ){
        celsius = 5 * (fahr - 32) / 9;
        if (fahr != 260 && fahr != 280 ) {
             printf("%4d    %4d\n", fahr, celsius);
        }
        fahr += 20;
    }
    return 0;
}
