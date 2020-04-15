//
//  main.c
//  practice_4_15
//
//  Created by edz on 2020/4/15.
//  Copyright © 2020 lioil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}BTree;

BTree* initBTree(int data);
BTree* insertBTree(BTree* *root, int n);
int searchBTree(BTree* root, int target);
void middle_order(BTree* root);

//初始化结点
BTree* initBTree(int data){
    BTree* root = (BTree*)malloc(sizeof(BTree));
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

//将结点插入到二叉树中，并且如果结点为NULL时新建结点
BTree* insertBTree(BTree* *root, int n){
    BTree *p = *root;
    if(p == NULL){
        *root = initBTree(n);
        return *root;
    }else if(n < p->data){
        //当插入数据小于当前结点的值时指向左子结点
        insertBTree(&p->lchild, n);
    }else{
        //当插入数据大于当前结点的值时指向右子结点
        insertBTree(&p->rchild, n);
    }
    return p;
}

//查找二叉树中的元素
int searchBTree(BTree* root, int target){
    //当当前结点为NULL时没有找到返回0
    if(root == NULL)return 0;
    //当要查找的数和当前结点的数相等时，返回1
    else if (target == root->data)return 1;
    //当要查找的数小于当前结点时，继续指向左子结点，再次查找判断
    else if(target < root->data) return searchBTree(root->lchild, target);
    //当要查找的数大于当前结点时，继续指向右子结点，再次查找判断
    else return searchBTree(root->rchild, target);
}


//使用中序遍历法将二叉搜索树将树中的元素从小到大进行打印
void middle_order(BTree* root){
    if(root != NULL){
        middle_order(root->lchild);
        printf("%d,", root->data);
        middle_order(root->rchild);
    }
}



int main(void) {
    BTree* root = (BTree*)malloc(sizeof(BTree));
    root = NULL;
    
    int temp;
    int a[]={2,5,20,1,9,12,11,10};
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<size; i++)insertBTree(&root, a[i]);
    
    
    printf("二叉树中元素从小到大排列为：");
    middle_order(root);
    printf("\n");
    
    printf("请输入要查找的数：");
    scanf("%d", &temp);
    if(searchBTree(root, temp))printf("%d在二叉树树中\n", temp);
    else printf("%d不在二叉树中\n", temp);
    
    return 0;
}
