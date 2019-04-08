#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
        ElemType data[MaxSize];//数组 也可用链表
        int top;
}SqStack;
void InitStack(SqStack &S)
{
        S.top=-1;//栈空
}

bool StackEmpty(SqStack &S)
{
        if(S.top==-1)
                return true;
        else
                return false;
}
//入栈
bool Push(SqStack &S,ElemType x)
{
        if(S.top==MaxSize-1)//数组的大小不能改变，避免访问越界
        {
                return false;
        }
        S.data[++S.top]=x;
        return true;
}
//出栈
bool Pop(SqStack &S,ElemType &x)
{
        if(-1==S.top)
                return false;
        x=S.data[S.top--];//后减减，x=S.data[S.top];S.top=S.top-1;
        return true;
}
//读取栈顶元素
bool GetTop(SqStack &S,ElemType &x)
{
        if(-1==S.top)//说明栈为空
                return false;
        x=S.data[S.top];
        return true;
}
int main()
{
        SqStack S;//先进后出 FILO  LIFO
        bool flag;
        ElemType m;//用来存放拿出的元素
        InitStack(S);//初始化
        flag=StackEmpty(S);
        if(flag)
        {
                printf("栈是空的\n");
        }
        Push(S,3);//入栈元素3
        Push(S,4);//入栈元素4
        Push(S,5);
        flag=GetTop(S,m);//获取栈顶元素
        if(flag)
        {
                printf("获取栈顶元素为 %d\n",m);
        }
        flag=Pop(S,m);//弹出栈顶元素
        if(flag)
        {
                printf("弹出元素为 %d\n",m);
        }
        system("pause");
}
