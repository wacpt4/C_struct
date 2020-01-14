//汉诺塔，是将重复步骤再简单化为一个步骤。
//将解决步骤分为，，将底层之上的挪到中间柱子，将底层移动到另一边的柱子
//先从第一层说起，
//1，A-》C,
//n=1,将第n层到C
//2，先要将A—》B，挪n-1层，然后第n层A-》C，最后n-1层，B-C
//n=2,n-1层要A->B，底层n=2,A->C，最后n-1层，B->C


//变成递归树，每一个分支将只有3步
//【1】n-1>B              |    |    |		|   |   |         |   |   |  
//【2】n>C				 ___  ___          ___     ___           ___ ___       
//【3】n-1>C			  A:n-1->B       A:n-(n-1)->C          B:(n-1)->C 

//至于递归和非递归


#include <iostream> 
//#include <fstream> 
//#include <iostream> 
using namespace std;
//ofstream fout("D:\\out.txt");
void Move(int n, char x, char y)
{
    //fout << "把" << n << "号从" << x << "挪动到" << y << endl;
    cout << "把" << n << "号从" << x << "挪动到" << y << endl;
}
void Hannoi(int n, char a, char b, char c)

{
    if (n == 1)
        Move(1, a, c);
    else
    {
        Hannoi(n - 1, a, c, b);
        Move(n, a, c);
        Hannoi(n - 1, b, a, c);
    }
}
int main()
{
    //fout << "以下是7层汉诺塔的解法:" << endl;
    cout << "以下是7层汉诺塔的解法:" << endl;
    Hannoi(7, 'a', 'b', 'c');
    //fout.close();
    cout << "输出完毕！" << endl;
    return 0;
}

//https://blog.csdn.net/u010177286/article/details/45404863 
//分装（main.c .h hanno.h分开放）
//奇数的第一个应该放到c号柱子
//偶数的第一个应该放b
