// 题目描述
// •连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
// •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

// 输入描述:
// 连续输入字符串(输入多次,每个字符串长度小于100)

// 输出描述:
// 输出到长度为8的新字符串数组

// 示例1
// 输入
// 复制
// abc
// 123456789
// 输出
// 复制
// abc00000
// 12345678
// 90000000

#include "../inc/global.h"

int main(int argc, char *argv[])
{
    int i,j,printindex;
    unsigned char strings[100];
    unsigned char *printfbuff;

    printindex = 0;
    printfbuff = malloc(8);
    memset(printfbuff, 0, 8);

    while(~scanf("%s", &strings))
    {
        if(strlen(strings) % 8 == 0)
        {
            printf("%s\r\n", strings);
            break;
        }
        else
        {
            for(i = 0; i < strlen(strings) / 8; i++)
            {
                memset(printfbuff, 0, 8);
                memcpy(printfbuff, &strings[printindex], 8);
                printf("%s\r\n", printfbuff);
                printindex += 8;
            }

            memset(printfbuff, 0, 8);
            memcpy(printfbuff, &strings[printindex], strlen(strings) - printindex);
            memcpy(printfbuff + strlen(strings) - printindex, "00000000", 8 - strlen(strings) + printindex );
            printf("%s\r\n", printfbuff);
            break;
        }
    }

    free(printfbuff);

    return 0;
}