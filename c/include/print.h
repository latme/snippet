/*
 * __FILE__
 * __LINE__
 * __FUNCTION__
 * __DATE__
 * __TIME__
 *
 */
#ifndef PRINT_H_
#define PRINT_H_

typedef enum
{
    ePrintNone,
    ePrintError,
    ePrintWarning,
    ePrintInfo,
    ePrintDebug,

    ePrintTop
}E_PrintLevel;


#define PRINT_RAW(fmt, args...)     logmsg(fmt, ##args)
#define PRINT_FMT(level, fmt, ...)  \
        if(gePrintLevel >= (level)) \
            PRINT_RAW("%s:%u "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define PRINT_ERR(fmt, ...)     PRINT_FMT(ePrintError,    fmt, ##__VA_ARGS__)
#define PRINT_WRN(fmt, ...)     PRINT_FMT(ePrintWarning,  fmt, ##__VA_ARGS__)
#define PRINT_INF(fmt, ...)     PRINT_FMT(ePrintInfo,     fmt, ##__VA_ARGS__)
#define PRINT_DBG(fmt, ...)     PRINT_FMT(ePrintDebug,    fmt, ##__VA_ARGS__)

#ifndef DEBUG
#undef  PRINT_DBG
#define PRINT_DBG(fmt, ...)
#endif



extern E_PrintLevel gePrintLevel;


#endif  /* PRINT_H_ */

