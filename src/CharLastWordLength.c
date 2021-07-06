#include "../inc/global.h"

int main(int argc, char *argv[])
{
#if 0
    int i,j;
    char s[5000] = {0};
    char input = 0;
    char output = 0;
    while(1)        //循环读取输入
    {
        if( (input = getchar()) != '\n')
        {
            s[i] = input;
        }
        else
        {
            s[i] = '\0';
            break;
        }
        i++;
    }

    if(isalpha(s[strlen(s)-1]) == 0)
    {
        puts("input string illegal");
        return -1;
    }
    // printf("last index is: %d\r\n", strlen(s)-1);
    // printf("last char is: %c\r\n", s[strlen(s)-1]);
    // printf("input string is: %s\r\n", s);
    Trace("warning", "input string is: %s\r\n", s);
    j = 0;
    for(i = strlen(s) - 1; i > 0; i--)
    {
        Trace("info", "start check word\r\n");
        if( s[i] == '\040')
        {
            Trace("info", "find space\r\n");
            output = strlen(s) -1 -i;
            Trace("info", "output = %d\r\n", output);
            printf("%d\r\n", output);
            break;
        }
        else
        {
            j++;
        }
    }
    Trace("info", "j = %d\r\n", j);
    if( (j + 1) == strlen(s))
    {
        printf("%d\r\n", j);
    }
#else
    #if 0
    char * s[5000];
    int count = 0;
    int index = 0;
    while(scanf("%c", &s[index]) != EOF)
    {
        if(s[index] ==' ')
        {
            count = 0;
        }
        else
        {
            count++;
        }
        index++;
    }
    printf("%d\n", count - 1);
    #endif
    
    char str[5000];
    while(scanf("%s",&str)!=EOF);
    printf("%d\r\n",(strlen(str)));

#endif
    return 0;
}

