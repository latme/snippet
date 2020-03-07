/*
 * stdarg.h数据类型
 * ==============================================
 * 类型名称  描述                            相容
 * ----------------------------------------------
 * va_list   用来保存va_arg和va_end所需信息  C89
 * ==============================================
 *
 * stdarg.h宏
 * ==============================================
 * 名称      描述                       相容
 * ----------------------------------------------
 * va_start  使用va_list指向起始的参数  C89
 * va_arg    检索参数                   C89
 * va_end    释放va_list                C89
 * va_copy   拷贝va_list的内容          C99
 * ==============================================
 *
 */
#include <stdarg.h>

#include <print.h>


E_PrintLevel gePrintLevel = ePrintDebug;


int logmsg(const char *fmt, ...)
{
    va_list args;
    int     cnt;

    va_start(args, fmt);
    cnt = vprintf(fmt, args);
    va_end(args);

    return cnt;
}

