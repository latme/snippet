/*
 * filename: basemacro.h
 */


#ifndef BASEMACRO_H_
#define BASEMACRO_H_


#define ARRAY_ELEMENTS(a)       (sizeof(a) / sizeof(a[0]))


#define MIN(x, y)               (((x) <= (y)) ? (x) : (y))
#define MAX(x, y)               (((x) >= (y)) ? (x) : (y))

#define WRAP_INC(var, max)      var = var + 1 < max ? var + 1 : 0
#define WRAP_DEC(var, max)      var = var     > 0   ? var - 1 : max - 1
#define WRAP_ADD(var, val, max) var = val < max ? (var < max - val ? var + val : var - (max - val)) \
                                                : (var + val % max) % max
#define WRAP_SUB(var, val, max) var = val < max ? (var >= val ? var - val : max - val + var) \
                                                : (max + var - val % max) % max



/** register read/write */
#define REGR8(reg_addr)         (*(volatile u8*) (reg_addr))
#define REGR16(reg_addr)        (*(volatile u16*)(reg_addr))
#define REGR32(reg_addr)        (*(volatile u32*)(reg_addr))
#define REGR64(reg_addr)        (*(volatile u32*)(reg_addr))
#define REGW8(reg_addr, value)  {*(volatile u8*) (reg_addr) = (u8)(value);}
#define REGW16(reg_addr, value) {*(volatile u16*)(reg_addr) = (u16)(value);}
#define REGW32(reg_addr, value) {*(volatile u32*)(reg_addr) = (u32)(value);}
#define REGW64(reg_addr, value) {*(volatile u64*)(reg_addr) = (u64)(value);}


/** align operations */
/** n must be power of 2 */
#define IS_POWEROF_2(n)         ( ((n) & ~(n)) == 0 )
#define ALIGN_UP(x, n)          ( (((u64)(n) - 1ULL) + (x)) & ~((u64)(n) - 1ULL)
#define ALIGN_DOWN(x, n)        ( ((                   (x)) & ~((u64)(n) - 1ULL)
#define ALIGN_ARCH(x)           ALIGN_UP(sizeof(void*))


/** endian operations */
#define ENDIAN_SWAP16(x)        ( (((x) & 0xFF00U) >> 8) | \
                                  (((x) & 0x00FFU) << 8) )
#define ENDIAN_SWAP32(x)        ( (((x) & 0xFF000000UL) >> 24) | \
                                  (((x) & 0x00FF0000UL) >>  8) | \
                                  (((x) & 0x0000FF00UL) <<  8) | \
                                  (((x) & 0x000000FFUL) << 24) )
#define ENDIAN_SWAP64(x)        ( (((x) & 0xFF00000000000000ULL) >> 56) | \
                                  (((x) & 0x00FF000000000000ULL) >> 40) | \
                                  (((x) & 0x0000FF0000000000ULL) >> 24) | \
                                  (((x) & 0x000000FF00000000ULL) >>  8) | \
                                  (((x) & 0x00000000FF000000ULL) <<  8) | \
                                  (((x) & 0x0000000000FF0000ULL) << 24) | \
                                  (((x) & 0x000000000000FF00ULL) << 40) | \
                                  (((x) & 0x00000000000000FFULL) << 56) )

/** buffer references
 *
 *       BufIdx
 * +------+                     +------+                +------+                +------+
 * |      | 0 <--- RdIdx,WrIdx  |//////| 0 <--- RdIdx   |//////| 0 <--- RdIdx   |      | 0
 * +------+                     +------+                +------+                +------+
 * |      | 1                   |//////| 1              |//////| 1              |//////| 1 <--- RdIdx
 * +------+                     +------+                +------+                +------+
 * |      | 2                   |      | 2 <--- WrIdx   |//////| 2              |//////| 2
 * +------+                     +------+                +------+                +------+
 * |      | 3                   |      | 3              |//////| 3              |//////| 3
 * +------+                     +------+                +------+                +------+
 * |      | 4                   |      | 4              |      | 4 <--- WrIdx   |      | 4 <--- WrIdx
 * +------+                     +------+                +------+                +------+
 * BufNum = 5                   BufNum = 5              BufNum = 5              BufNum = 5
 * (EMPTY)                                              (FULL: WrIdx >= RdIdx)
 *
 *                              +------+                +------+
 *                              |//////| 0              |//////| 0
 *                              +------+                +------+
 *                              |      | 1 <--- WrIdx   |//////| 1
 *                              +------+                +------+
 *                              |      | 2              |      | 2 <--- WrIdx
 *                              +------+                +------+
 *                              |//////| 3 <--- RdIdx   |//////| 3 <--- RdIdx
 *                              +------+                +------+
 *                              |//////| 4              |//////| 4
 *                              +------+                +------+
 *                              BufNum = 5              BufNum = 5
 *                                                      (FULL:  WrIdx < RdIdx)
 *
 * --------------------------------------------------------------------
 *             WrIdx >= RdIdx                   WrIdx < RdIdx
 * --------------------------------------------------------------------
 * IS_EMPTY   (WrIdx == RdIdx)
 * IS_FULL    (WrIdx - RdIdx == BufNum - 1)    (WrIdx + 1 == RdIdx)
 * NUM_USED   (WrIdx - RdIdx)                  (BufNum + WrIdx - RdIdx)
 * NUM_IDLE   (BufNum - 1 - WrIdx + RdIdx)     (RdIdx - WrIdx - 1)
 * --------------------------------------------------------------------
 */
#define BUF_IS_EMPTY(wi, ri)                    ((wi) == (ri))
#define BUF_IS_FULL (wi, ri, num)               ((wi) + 1 == (ri) || (wi) - (ri) == (num) - 1)
#define BUF_NUM_USED(wi, ri, num)               ((wi) >= (ri) ? (wi) - (ri) : (num) - (ri) + (wi))
#define BUF_NUM_IDLE(wi, ri, num)               ((wi) <  (ri) ? (ri) - (wi) - 1 : (num) - 1 - (wi) + (ri))


/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member.
 * @type:   the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 */
#define offsetof(type, member)                  ((size_t)&((type*)0)->member)
#define container_of(ptr, type, member)         ((type*)((char*)(ptr) - offsetof(type, member)))

/** for_each_* */
#define for_each_array(p, a)                    for(p = a;    p < a + ARRAY_ELEMENTS(a);              (p)++)
#define for_each_array_p(i, p, a)               for(p = a, i = 0; i < ARRAY_ELEMENTS(a);              (p)++, (i)++)
#define for_each_array_e(i, e, a)               for(       i = 0; i < ARRAY_ELEMENTS(a) && (e = a[i], TRUE); (i)++)
#define for_each_table(p, t, n)                 for(p = t;    p < t + (n);          (p)++)
#define for_each_table_p(i, p, t, n)            for(p = t, i = 0; i < (n);          (p)++, (i)++)
#define for_each_table_e(i, e, t, n)            for(       i = 0; i < (n) && (e = (t)[i]); (i)++)
#define for_each_tabnn(p, t)                    for(p = t;        ;            (p)++)
#define for_each_tabnn_p(i, p, t)               for(p = t, i = 0; ;            (p)++, (i)++)
#define for_each_tabnn_e(i, e, t)               for(       i = 0; (e = (t)[i], TRUE); (i)++)
#define for_each_seq(i, base, top)              for(i = base; i < top; (i)++)





#endif /* BASEMACRO_H_ */

