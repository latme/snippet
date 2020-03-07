/*
 * filename: basetype.h
 *
 *
 *  variable naming rules：
 *  ---------------------------
 *  prefix  meaning
 *  ---------------------------
 *  u       unsigned integer
 *  i       signed integer
 *  b       bool
 *  p       pointer
 *  a       array
 *  f       function
 *  g       global
 *  l       local
 *  t       type: struct/union
 *  e       enumeration: enum
 *  ---------------------------
 *
 */

#ifndef BASETYPE_H_
#define BASETYPE_H_


/** base type */
typedef int                 bool;
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;
typedef signed char         i8;
typedef signed short        i16;
typedef signed long         i32;
typedef signed long long    i64;

#define TRUE                (bool)1
#define FALSE               (bool)0
#define NULL                (void*)0







#endif /* BASETYPE_H_ */

