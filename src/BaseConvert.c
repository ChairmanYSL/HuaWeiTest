#include "../inc/global.h"

s32 main(void)
{
    u8 *ucHex = NULL;
    u8 *ucBcd = NULL;
    u8 *ucBin = NULL;
    s32 siDecLen = 0;
    s32 i = 0;
    s32 j =0;
    u8 p;

    ucHex = (u8 *)malloc(1024);
    memset(ucHex, 0, 1024);

    ucBcd = (u8 *)malloc(512);
    memset(ucBcd, 0, 512);

    ucBin = (u8 *)malloc(8);
    memset(ucBin, 0, 8);

    printf("请输入要转换的数(Hex):");
    while(1)
    {
        p = getchar();
        if(p == '\n' || ((s32)p == 255))    //遇到了Enter或者Ctrl D认为输入结束
        {
            if((s32)p == 255)
            {
                printf("\r\n");
                return SDK_ERR;
            }
            break;
        } 
        else
        {
            if(p != ' ')
            {
                ucHex[i++] = p;
            }
        }
    }
    
    printf("buf len = %d\r\n",strlen(ucHex));
    if(!strlen(ucHex))
    {
        printf("\r\n");
        return SDK_ERR;
    }

    siDecLen = AscToBcd(ucBcd, ucHex, strlen(ucHex));

    printf("转换后的数(Dig):\r\n");
    for(i = 0; i < siDecLen; i++)
    {
        printf("%d ", *(ucBcd+i));
    }
    printf("\r\n");
    
    printf("转换后的数(Bin):\r\n");    
    for(i = 0; i < siDecLen; i++)
    {
        // printf("%d\r\n", *(ucBcd+i));
        j = 0;
        memset(ucBin, 0, 8);
        do
        {
            *(ucBin+j) = *(ucBcd+i) % 2;
            // printf("转换为二进制第%d位为：%d\r\n", j + 1, *(ucBin+j));
            j++;
        }while((*(ucBcd+i) /= 2) != 0);
        for(j = 7; j >= 0; j--)
        {
            printf("%d", *(ucBin+j));
        }
        printf("\r\n");
        for(j = 7; j >= 0; j--)
        {
            if(*(ucBin+j) == 1)
            {
                printf("Bit %d  ", j + 1);
            }
        }        
        printf("\r\n");
    }
    printf("\r\n");
    free(ucHex);
    free(ucBcd);
    free(ucBin);
    ucHex = NULL;
    ucBcd = NULL;
    ucBin = NULL;

    return SDK_OK;
}