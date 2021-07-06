#include "../inc/global.h"
//起始位置不能超过总长度减最后一个数组的长度
//结束位置不能超时总长度
//先排序后去重

int main(int argc, char *argv[])
{
    int numbers[1000] = {0};
    int count[1000] = {0};
    int N;
    int i = 0;
    int j;
    int k = 0;
    // int l;
    int start;
    int end = 0;
    int temp;
    int count_len;
    int number_len;
    int numbers_len;

    while(1)    //循环读取数组
    {
        if(scanf("%d", &N) != EOF)
        {
            if(N != 0)
            {
                count[i++] = N;
                for(j = 0; j < N; j++)
                {
                    scanf("%d", &numbers[k++]);
                }
            }
        }
        else
        {
            break;
        }
    }

    count_len = i;
    numbers_len = k;
    // printf("count_len = %d\r\n", count_len);
    // printf("all numbers_len = %d\r\n", numbers_len);
    
    // printf("count array:\n");
    // for(l = 0; l < count_len; l++)
    // {
    //     printf("%d\040",count[l]);
    // }
    // printf("\n");

    for(i = 0; i < count_len; i++)      //将数据分组操作
    {
        if(count[i] > 0)
        {
            if(i == 0)
            {
                start = i;
            }
            else
            {
                start += count[i-1];
            }
            end += count[i];
            // printf("i = %d\n", i);
            // printf("array %d len = %d\n", i+1, count[i]);
            // printf("start index = %d\r\n", start);
            // printf("end index = %d\r\n", end);
            // printf("before sort array %d:\r\n", i+1);
            // for(l = start; l < end; l++)
            // {
            //     printf("%d\040",numbers[l]);
            // }
            // printf("\n");

            for(j = 0 ; j < count[i] -1; j++) //冒泡排序,第一个循环控制排序次数,index是可以从0开始的，结束条件应该用长度，这样第二个循环就可以减去index了
            {
                for(k = start; k < end -1 -j; k++)
                {
                    if(numbers[k] > numbers[k+1])
                    {
                        temp = numbers[k];
                        numbers[k] =  numbers[k+1];
                        numbers[k+1] = temp;
                    }
                }   
            }
            // printf("after sort array %d:\r\n",i+1);
            // for(l = start; l < end; l++)
            // {
            //     printf("%d\040",numbers[l]);
            // }
            // printf("\n");

            for(j = start; j < end; j++)
            {
                for( k = j + 1; k < end; k++)
                {
                    if(numbers[j] == numbers[k])
                    {
                        numbers[k] = '\0';
                    } 
                }
            }

            // printf("after De-duplicate array %d:\r\n",i+1);
            // for(l = start; l < end; l++)
            // {
            //     if(numbers[l] != '\0')
            //     {
            //         printf("%d\040",numbers[l]);
            //     }
            // }
            // printf("\n");
            
        }
    }
    // printf("final dedump\r\n");
    for(i = 0; i < numbers_len; i++)
    {
         if(numbers[i] != '\0')
         {
            printf("%d\n",numbers[i]);
         }
    } 
    return 0;
}