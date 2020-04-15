//
//  main.c
//  practice_2
//
//  Created by edz on 2020/4/9.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    int top;
    int size;
    int* data;
} Stack;

// 初始化一个最多可以存放size个整数的栈
Stack* initStack(int size) {
    Stack* pStack = malloc(sizeof(Stack));
    pStack->data = malloc(sizeof(int) * size);
    pStack->top = 0; // top代表下一个入栈的位置，所以top-1才表示当前的栈顶
    pStack->size = size;
    return pStack;
}

// 当这个栈满的时候应该返回0，表示push失败
int push(int elem, Stack* ps) {
    if (ps->top == ps->size) {
        // 当size为5的时候，top从0到4是有效的，所以top为5的时候是无效的
        printf("栈满了，不能push\n");
        return 0;
    }
    
    ps->data[ps->top] = elem;
    ps->top++;
    return 1;
}

// pop需要返回成功还是失败，又需要返回一个数值
int pop(Stack* ps, int* result) {
    if (ps->top == 0) {
        // 空栈
        printf("空栈，不能pop\n");
        return 0;
    }
    /*
    *result = ps->data[ps->top-1];
    ps->top--;
     */
    *result = ps->data[--(ps->top)];
    return 1;
}

int peek(Stack* ps, int * result) {
    if (ps->top == 0) {
        // 空栈
        printf("空栈，不能peek\n");
        return 0;
    }

    *result = ps->data[ps->top-1];
    return 1;
}


int rpn(char* a) {
    int i = 0, b, c, sum, result;
    int len = sizeof(a)/sizeof(a[0]);
    Stack* ps = initStack(len);

    
    while(a[i] != '\0'){
        if(a[i] >= '0' && a[i] <= '9'){
            sum=0;
            sum=a[i]-'0';
            i++;
            push(sum,ps);
        }
        //3. 遇到运算符（#），则将栈中的前两个数字（a和b）出栈，并将b#a的值压入栈中。
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
                {
                    pop(ps,&b);
                    pop(ps,&c);
                    if(a[i]=='+')
                        push(b+c,ps);
                    else if(a[i]=='-')
                        push(c-b,ps);
                    else if(a[i]=='*')
                        push(c*b,ps);
                    else if(a[i]=='/')
                        push(c/b,ps);
                    else
                        printf("error\n");
                }
                i++;
    }
    pop(ps, &result);
    return result;
}


int main(void) {
    char a[] = "3 4 2 * + 5 3 * -";
    int r = rpn(a);
    printf("结果为%d\n", r);
    
    return 0;
}
