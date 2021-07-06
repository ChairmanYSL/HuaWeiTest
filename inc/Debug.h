#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_SWITCH
#undef DEBUG_SWITCH

extern void sdkDebugTrace(const char *pasTag, const char *pasFunc, const char *pasFile, int line, const char *pheFormat, ...);

#ifdef DEBUG_SWITCH
#define Trace(ptag, arg...) sdkDebugTrace((const char *)ptag, (const char *) __FUNCTION__, (const char *) __FILE__, __LINE__, ##arg )
#else
#define Trace(ptag, arg...)
#endif

extern void *sdkDebugGetMem(s32 siSize, const u8 *pasFile, u32 puiLine);
#define sdkGetMem(siSize) sdkDebugGetMem((s32)siSize, (u8 *)__FILE__, (u32)__LINE__)


#endif
