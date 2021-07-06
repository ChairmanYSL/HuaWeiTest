#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H

#ifndef u8
#define u8 unsigned char
#endif

#ifndef u16
#define u16 unsigned short
#endif

#ifndef u32
#define u32 unsigned int
#endif

#ifndef u64
#define u64 unsigned long
#endif

#ifndef u128
#define u128 unsigned long Looking
#endif

#ifndef s8
#define s8 signed char
#endif

#ifndef s16
#define s16 signed short
#endif

#ifndef s32
#define s32 signed int
#endif

#ifndef s64
#define s64 signed long
#endif

#ifndef s128
#define s128 signed long long
#endif

#define SDK_OK 0
#define SDK_ERR -1
#define SDK_PARAM_ERR -2

//使用字符串来盛放32位和64位有符号数最大需要几个字符空间。
#define INT32_LEN   (sizeof("-2147483648") - 1)
#define INT64_LEN   (sizeof("-9223372036854775808") - 1)

typedef struct
{
    unsigned int TransAmt;             /* Transaction amount */
    unsigned char TransType;         	/* Transaction type BCD */
    unsigned char TSI[2];                /* Transaction Status Information */
    unsigned char PANLen;
    unsigned char PAN[10];           	/* Primary account No. */
    unsigned char PANSeq;                /* EMVTest: sequence num with same PAN */
    unsigned char TransDate[3];      	/* Trancaction Date(Form:"YY/MM/DD") */
    unsigned char TransTime[3];      	/* Trancaction Time(Form:"HH/MM/SS") */
	unsigned char TransCount[4];		/* Transaction Sequence Counter. increase by 1 for each trans*/
} L2_TRANS_LOG;


#endif