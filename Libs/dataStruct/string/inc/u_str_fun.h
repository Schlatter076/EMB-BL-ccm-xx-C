////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "u_str_fun.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __U_STR_FUN_H_KENSKY_2012_12_15
#define __U_STR_FUN_H_KENSKY_2012_12_15

/**** Includes ****************************************************************/
#include "../../DS_cfg.h"

#if (defined __STRING_MODULE) && (__STRING_MODULE == _DS_MODULE_is_ON)

#ifdef WIN32
#include <windows.h>
#else
#define BOOL int
#ifndef TRUE
#define TRUE ('\x01')
#endif
#ifndef FALSE
#define FALSE ('\x00')
#endif
#endif

#ifdef __cplusplus
extern"C"{
#endif

#define MAX_STRING_SIZE (1024ul)

#define STRNLEN(szDest) strnlen(szDest,MAX_STRING_SIZE)
#define COPYSTRN(szDest,iDestMaxSize,szSource) CopyStrN(szDest,iDestMaxSize,szSource,STRNLEN(szSource)+1)
#define COPYSTRNN(szDest,szSource) COPYSTRN(szDest,MAX_STRING_SIZE,szSource)
#define APPENDSTRN(szDest,iDestMaxSize,szSource) AppendStrN(szDest,iDestMaxSize,szSource,STRNLEN(szSource)+1)
#define APPENDSTRNN(szDest,szSource) APPENDSTRN(szDest,MAX_STRING_SIZE,szSource)

//功能描述：带保护的字符串拷贝（目标缓冲区限定长度）
//返回值：完整拷贝返回TRUE，否则返回FALSE。
//参数说明：iDestMaxSize：目标的最大尺寸（包含结尾的NULL）。
//          iSourceLen：原始的长度（不包含结尾的NULL），如果小于0，不拷贝并且返回FALSE。
BOOL CopyStrN(char*szDest,int iDestMaxSize,char const*szSource,int iSourceLen);

//功能描述：带保护的字符串拼接（目标缓冲区限定长度）
//返回值：完整拼接返回TRUE，否则返回FALSE。
//参数说明：iDestMaxSize：目标的最大尺寸（包含结尾的NULL）。
//          iSourceLen：原始的长度（不包含结尾的NULL），如果小于0，不拼接并且返回FALSE。
BOOL AppendStrN(char*szDest,int iDestMaxSize,char const*szSource,int iSourceLen);

//功能描述：测试字符串的长度。
//返回值：Dest的长度。如果在[Dest,Dest+iMaxSize-1]内没有找到NULL，返回-2。如果Dest==NULL，返回-2。
//参数说明：iMaxSize：Dest最大尺寸（包含结尾的NULL）。
//int strnlen(char const*szDest,int iMaxSize); // todo redeclaration

//功能描述：去除字符串开始的空白（space & tab）
//参数说明：*pszStr原始字符串
void trimbegin(char**const pszStr);

//功能描述：去除字符串开始和结束的空白（space & tab）
//参数说明：*pszStr原始字符串
void strtrim(char**const pszStr);

//功能描述：测试字符串是否全部由数字（0-9）组成。
//返回值：如果全部由数字（0-9）组成，返回TRUE，否则返回FALSE。
//参数说明：szStr字符串
BOOL IsStrDigits(char const*szStr);

//将IP-v4（big-endian）转换成字符串（点分十进制）
//返回：pBuf
//参数说明：pBuf字符串存放地址，必须保证不小于16字节空间。ip：IP地址。
char *inet_n2a(char pBuf[16],unsigned long const ip);

//查找匹配内存块
//返回：submem第一次出现在mem的索引。如果找不到，返回memlen。
int memmem(void const*mem,int memlen,void const*submem,int submemlen);

#ifndef WIN32
//库函数，Lamda Tool 没有定义，此处列出原型
int _stricmp(const char *, const char *);

//库函数，Lamda Tool 没有定义，此处列出原型
int _memicmp(const void *, const void *, unsigned int);

#endif

#ifdef __cplusplus
}
#endif

#endif // (defined __STRING_MODULE) && (__STRING_MODULE == _DS_MODULE_is_ON)

#endif // __U_STR_FUN_H_KENSKY_2020-12-15
