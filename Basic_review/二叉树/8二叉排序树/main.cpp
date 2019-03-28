#include <stdio.h>
#include <stdlib.h>


typedef int KeyType;
typedef struct BSTNode{
        KeyType key;
        struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;

int BST_Insert(BiTree &T,KeyType k)
{
        if(NULL==T)
        {
                T=(BiTree)malloc(sizeof(BSTNode));
                T->key=k;
                T->lchild=T->rchild=NULL;
                return 1;
        }
        else if(k==T->key)
                return 0;
        else if(k<T->key)
                return BST_Insert(T->lchild,k);
        else
                return BST_Insert(T->rchild,k);
}

void Creat_BST(BiTree &T,KeyType str[],int n)
{
        T=NULL;
        int i=0;
        while(i<n)
        {
                BST_Insert(T,str[i]);
                i++;
        }
}
//递归算法简单，但执行效率较低，实现留给大家编写
BSTNode *BST_Search(BiTree T,KeyType key,BiTree &p)
{
        p=NULL;
        while(T!=NULL&&key!=T->key)
        {
                p=T;
                if(key<T->key) T=T->lchild;
                else T=T->rchild;
        }
        return T;
}
//这个书上没有
void DeleteNode(BiTree &root,KeyType x){
    if(root == NULL){
        return;
    }
    if(root->key>x){
        DeleteNode(root->lchild,x);
    }else if(root->key<x){
        DeleteNode(root->rchild,x);
    }else{ //查找到了删除节点
        if(root->lchild == NULL){ //左子树为空
           BiTree tempNode = root;
           root = root->rchild;
           free(tempNode);
        }else if(root->rchild == NULL){ //右子树为空
           BiTree tempNode = root;
           root = root->lchild;
           free(tempNode);
        }else{  //左右子树都不为空
            //一般的删除策略是左子树的最大数据 或 右子树的最小数据 代替该节点(这里采用查找左子树最大数据来代替)
            BiTree tempNode = root->lchild;
            if(tempNode->rchild!=NULL){
                tempNode = tempNode->rchild;
            }
            root->key = tempNode->key;
            DeleteNode(root->lchild,tempNode->key);
        }
    }
}

void InOrder(BiTree T)
{
        if(T!=NULL)
        {
                InOrder(T->lchild);
                printf("%3d",T->key);
                InOrder(T->rchild);
        }
}
int main()
{
        BiTree T;
        BiTree parent;
        BiTree search;
        //KeyType str[]={54,20,66,40,28,79,58};
        //Creat_BST(T,str,7);
        KeyType str[]={54,20,40,28,79,58,78,81,55,60,62};
        Creat_BST(T,str,11);
        //KeyType str[]={54,20,66,40,28,79,58,78,81,55,60,62};
        //Creat_BST(T,str,12);
        InOrder(T);
        printf("\n");
        search=BST_Search(T,41,parent);
        if(search)
        {
                printf("找到对应结点，值=%d\n",search->key);
        }else{
                printf("未找到对应结点\n");
        }
        DeleteNode(T,40);
        InOrder(T);
        printf("\n");
        system("pause");
}
