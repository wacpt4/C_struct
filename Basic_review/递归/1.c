#include<stdio.h>

/*小明为了学好英语，需要每天记单词，第一天记1个，第二天记2个依次类推，到第10天的时候小明一共记了多少个单词？
9
请用代码完成，算出小明第10天开始的时候会了多少个单词？*/ 
 static int count = 0;

int a(n){
	if(n==1)
	{
		return 1;	
	}
	else{
		return a(n-1)+n;
	}
}
int main(){
	int n= a(10);
printf("%d",n);
} 


/*
递归函数名（）
{
if
递归出口
else
递归主体递归函数名	
	}
*/
