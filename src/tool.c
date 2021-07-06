#include "../inc/global.h"
void sdkDebugTrace(const char *pasTag, const char *pasFunc, const char *pasFile, int line, const char *pheFormat,...)
{
    u8 *buffer;
    va_list args;

    buffer = (u8 *)malloc(1024);    //手动分配内存并初始化
    memset(buffer, 0, 1024);    

    sprintf(buffer, "Tag:%s  File:%s  Function:%s  Line:%d\r\n", pasTag, pasFile, pasFile, line);
    va_start(args, pheFormat);  //将传给函数的最后一个已知固定的参数传进来，将剩下的不定参数都存到队列里
    vsprintf(&buffer[strlen(buffer)], pheFormat, args);     //格式化打印
    printf(buffer);
    va_end(args);

    free(buffer);
}