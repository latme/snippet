/**
 * file: lattypes.h
 */


#ifndef __LATTYPES_H__
#define __LATTYPES_H__


#define USE_STDDEF_H
#ifdef  USE_STDDEF_H
#include <stddef.h>
#endif


typedef int bool;
#define TRUE                    1
#define FALSE                   0
#ifndef USE_STDDEF_H
#define NULL                    (void*)0
#endif


typedef   signed char           s8;
typedef   signed short          s16;
typedef   signed int            s32;
typedef   signed long long      s64;
typedef unsigned char           u8;
typedef unsigned short          u16;
typedef unsigned int            u32;
typedef unsigned long long      u64;



#endif /* LATTYPES_H_ */

