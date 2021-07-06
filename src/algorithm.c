#include "../inc/global.h"
/*******************************************************************
   版          权: lishiyao
   作          者: lishiyao
   函数名称: s32 bubble_sort(u8 *array, s32 len)
   函数功能: 冒泡排序
   输入参数: u8 *array :待排序的数组;
            s32 len:数组长度
   输出参数:u8 *array:排序后的数组
   返   回  值: 0
   修改备注: 
   日期时间: 2021.06.18 09:38:00
*******************************************************************/
s32 bubble_sort(u8 *array, s32 len)
{
    s32 i,j,temp;

    for(i = 0; i < len -1; i++)
    {
        for(j = 0; j < len - 1 -i; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    return SDK_OK;
}

/*******************************************************************
   版          权: lishiyao
   作          者: lishiyao
   函数名称: s32 De_duplication(u8 *array, s32 len)
   函数功能: 数组去重
   输入参数: u8 *array :待去重的数组;
            s32 len:数组长度
   输出参数:u8 *array:去重后的数组
   返   回  值: 0
   修改备注: 
   日期时间: 2021.06.18 09:38:00
*******************************************************************/
s32 De_duplication(u8 *array, s32 len)
{
    s32 i,j;

    for(i = 0; i < len; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(array[j] == array[i])
            {
                array[j] = '\0';
            }        
        }
    }

    return SDK_OK;
}
/*******************************************************************
   版          权: lishiyao
   作          者: lishiyao
   函数名称: void sdkDebugGetMem(s32 siSize,const u8 *pasFile, u32 puiLine)
   函数功能: 标记申请内存的地方
   输入参数: s32 siSize:申请的内存大小;
            const u8 *pasFile:文件名;
            u32 puiLine：行数
   输出参数:无
   返   回  值: void类型的指针
   修改备注: 
   日期时间: 2021.06.18 09:38:00
*******************************************************************/
void *sdkDebugGetMem(s32 siSize,const u8 *pasFile, u32 puiLine)
{
    void *p = NULL;

    p = (void *) malloc(siSize);
    printf("get mem at Line %d of %s\r\n", puiLine, pasFile);
    return p;
}
/*******************************************************************
   版          权: lishiyao
   作          者: lishiyao
   函数名称: s32 AscToInt(u8 pbinDest ,u8 *phexSrc, s32 siSrcLen)
   函数功能: ASCII码转成BCD码
   输入参数: s32 siSize:申请的内存大小;
            const u8 *pasFile:文件名;
            u32 puiLine：行数
   输出参数:无
   返   回  值: void类型的指针
   修改备注: 
   日期时间: 2021.06.18 09:38:00
*******************************************************************/
s32 AscToBcd(u8 *pbcdDest ,u8 *phexSrc, s32 siSrcLen)
{
    s32 i;
    u8 highbit = 0;
    u8 lowbit = 0;
    //先判断源数据指针是否为空
    if(phexSrc == NULL || pbcdDest == NULL || siSrcLen < 0)
    {
        printf("传入参数错误，请检查!\r\n");
        return SDK_PARAM_ERR;
    }
    //再判断传进来的是否是
    for(i = 0; i < siSrcLen; i++)
    {
        if( *(phexSrc+i) < '0' || (*(phexSrc+i) > '9' && *(phexSrc+i) < 'A') || (*(phexSrc+i) > 'F' && *(phexSrc+i) < 'a') || *(phexSrc+i) > 'f')
        {
            printf("输入数据格式错误，请检查!\r\n");
            return SDK_PARAM_ERR;
        }
    }
    //数据转换
    for(i = 0; i < siSrcLen; i++)
    {
        // printf("高八位 phexSrc[%d] = %d\r\n", i, phexSrc[i]);    //对高八位进行转换
        if(*(phexSrc+i) >= '0' && *(phexSrc+i) <= '9')    //数字
        {
            // printf("数字\r\n");
            highbit = *(phexSrc+i) - 0x30;
        }
        else if(*(phexSrc+i) >= 'a' && *(phexSrc+i) <= 'f')   //小写
        {
            // printf("小写\r\n");
            highbit = *(phexSrc+i) - 0x57;
        }
        else if(*(phexSrc+i) >= 'A' && *(phexSrc+i) <= 'F') //大写
        {
            // printf("大写\r\n");
            highbit = *(phexSrc+i) - 0x37;  
        }
        else
        {
            // printf("无法识别的一律标记为FF\r\n");
            highbit = 0xFF; 
        }

        i++;
        if(i < siSrcLen)    //长度为偶数不补0
        {
            // printf("低八位 phexSrc[%d] = %d\r\n", i, *(phexSrc+i));   //对低八位进行转换
            if(*(phexSrc+i) >= '0' && *(phexSrc+i) <= '9')    //数字
            {
                // printf("数字\r\n");
                lowbit = *(phexSrc+i) - 0x30;
            }
            else if(*(phexSrc + i) >= 'a' && *(phexSrc + i) <= 'f')   //小写
            {
                // printf("小写\r\n");
                lowbit = *(phexSrc + i) - 0x57;
            }
            else if(*(phexSrc + i) >= 'A' && *(phexSrc + i) <= 'F') //大写
            {
                // printf("大写\r\n");
                lowbit = *(phexSrc + i) - 0x37;  
            }
            else
            {
                // printf("无法识别的一律标记为FF\r\n");
                lowbit = 0xFF; 
            }        
        }
        else    //长度为奇数要补0
        {
            printf("长度为奇数要补0\r\n");
            i--;    //长度减一让奇数变为偶数
            lowbit = 0x00;  //补0
        }
        *(pbcdDest + i / 2) = (highbit << 4) | lowbit; //合并高八位和低八位
    }

    return (siSrcLen + 1) /2;
}