#include "../inc/global.h"
#pragma pack(1)


s32 input(void)
{
    int n;
    int a;
    int i;
    while(~scanf("%d", &n))
    {
        int count[1001] = {0};
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a);
            count[a] = 1;
        }
        for (i = 0; i < 1001; i++)
        {
            if (count[i] == 1)
            {
                printf("%d\n", i);
            }
        }
    }
    
    return 0;

}

s32 input1(void)
{
    int i = 9;
    int base = 8;

    printf("%d\r\n", i / base);

}

s32 input2(void)
{
    char input[100];
    char p;
    int i = 0;
    int j = 0;
    int *count = NULL;
    char *dispbuff = NULL;
    int dispindex = 0;
    int len;
    count = (int *)malloc(10);
    memset(count, 0, 10);
    dispbuff = (char *)malloc(8);
    
    while(1)
    {
        p = getchar();
        if(p == EOF)
        {
            break;
        }
        else if(p == '\n')
        {
            *(count+j) = i;
            printf("array len : %d\r\n",*(count+j));
            j++;
            input[i++] = getchar();            
        }
        else
        {
            input[i++] = p;       
        }
    }
    printf("string len : %d\r\n", strlen(input));
    for(i = 0; i < strlen(input) - 1; i++)
    {
        printf("%c", input[i]);
    }
    printf("\n");

    for(i = 0; i < j; i++)
    {
        printf("%d\r\n", count[i]);
    }

    for(i = 0; i < j; i++)
    {
        if(!count[i])   //长度为0的话应该退出
        {
            printf("len invalid!   abort!\r\n");
            break;
        }

        for(j = 0; j < count[i] / 8; j++)
        {
            memset(dispbuff, 0, 8);
            memcpy(dispbuff, &input[dispindex], 8);
            dispindex += 8;
            printf("%s\r\n", dispbuff);
        }
        if(dispindex % 8 == 0)  //如果是8的倍数的循环完后应该退出
        {
            printf("already finish !   abort!\r\n");
            break;
        }
        memset(dispbuff, 0, 8);
        len = count[i] - 8 * (count[i] / 8);
        memcpy(dispbuff, &input[dispindex], len);
        dispindex += len;
        memcpy(dispbuff + len, "00000000", 8 - len);
        printf("%s\r\n", dispbuff);
    }

}

s32 input3(void)
{
    int *buf = NULL;
    int i;

    buf = (int *)malloc(10);
    memset(buf, 0, 10);

    for(i = 0; i < 10; i++)
    {
        *(buf+i) = i;
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d\r\n",buf[i]);
    }
}

s32 GetCharCtrlD(void)
{
    u8 p;

    p = getchar();
    printf("%c\r\n", p);
    printf("%d\r\n", p);
    printf("%d\r\n", EOF);
    return SDK_OK;
}

s32 bIsArrayNameInStructPointer(void)
{
    L2_TRANS_LOG translog = {0};
    s32 i;

    memset(&translog, 0, sizeof(translog));
    memcpy(translog.TransCount, "\x01\x01\x01\x01", 4);
    for(i = 0; i < 4; i++)
    {
        printf("%02x ", translog.TransCount[i]);
    }
    printf("\r\n");
    return SDK_OK;
}


s32 main(void)
{
    bIsArrayNameInStructPointer();
    return 0;
}