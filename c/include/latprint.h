/*
 * __FILE__
 * __LINE__
 * __FUNCTION__
 * __DATE__
 * __TIME__
 *
 */
#ifndef __LATPRINT_H__
#define __LATPRINT_H__




typedef enum
{
    ePrintNone,
    ePrintError,
    ePrintWarning,
    ePrintInfo,
    ePrintDebug,

    ePrintTop
}E_PrintLevel;


#define LATPRINT_RAW(fmt, args...)     logmsg(fmt, ##args)
#define LATPRINT_FMT(level, fmt, ...)  \
        if(gePrintLevel >= (level)) \
            LATPRINT_RAW("%s:%u "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define LATPRINT_ERR(fmt, ...)     PRINT_FMT(ePrintError,    fmt, ##__VA_ARGS__)
#define LATPRINT_WRN(fmt, ...)     PRINT_FMT(ePrintWarning,  fmt, ##__VA_ARGS__)
#define LATPRINT_INF(fmt, ...)     PRINT_FMT(ePrintInfo,     fmt, ##__VA_ARGS__)
#define LATPRINT_DBG(fmt, ...)     PRINT_FMT(ePrintDebug,    fmt, ##__VA_ARGS__)

#ifndef DEBUG
#undef  LATPRINT_DBG
#define LATPRINT_DBG(fmt, ...)
#endif



extern E_PrintLevel gePrintLevel;


#endif  /* __LATPRINT_H__ */

