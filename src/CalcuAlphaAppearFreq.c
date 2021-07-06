#include "../inc/global.h"

// 题目描述
// 写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字母，然后输出输入字符串中该字母的出现次数。不区分大小写。

// 输入描述:
// 第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字母。

// 输出描述:
// 输出输入字符串中含有该字符的个数。

// 示例1
// 输入

// ABCabc
// A
// 输出

// 2

//优化的解题思路：将第二次输入的字符统一转为小写字母再对比
int main(int argc, char *argv[])
{
    char s[5000] = {0};
    char compare;
    char input;
    int size = 0;
    int i,count;
//循环读取输入
    while(1)
    {
        if((input = getchar()) != '\n')
        {
            s[size++] = input;
        }
        else
        {
            compare = getchar();
            break;
        }
    }
    s[size] = '\0';

//遍历数组对比
    count = 0;
    for(i = 0; i < size; i++)
    {
        if( (compare == s[i]) || (compare == (s[i] + 32 )) || (compare == (s[i] - 32)) )
        {
            count++;
        }  
    }

    printf("%d\n", count);
    return SDK_OK;

}