/**
 * file: latmacros.h
 */


#ifndef __LATMACROS_H__
#define __LATMACROS_H__



/***********************************************************************************************************************
 * bit relevant macros
 **********************************************************************************************************************/
/** constant size */
#define SIZE_1B                 0x00000001UL
#define SIZE_2B                 0x00000002UL
#define SIZE_4B                 0x00000004UL
#define SIZE_8B                 0x00000008UL
#define SIZE_16B                0x00000010UL
#define SIZE_32B                0x00000020UL
#define SIZE_64B                0x00000040UL
#define SIZE_128B               0x00000080UL
#define SIZE_256B               0x00000100UL
#define SIZE_512B               0x00000200UL
#define SIZE_1KB                0x00000400UL
#define SIZE_2KB                0x00000800UL
#define SIZE_4KB                0x00001000UL
#define SIZE_8KB                0x00002000UL
#define SIZE_16KB               0x00004000UL
#define SIZE_32KB               0x00008000UL
#define SIZE_64KB               0x00010000UL
#define SIZE_128KB              0x00020000UL
#define SIZE_256KB              0x00040000UL
#define SIZE_512KB              0x00080000UL
#define SIZE_1MB                0x00100000UL
#define SIZE_2MB                0x00200000UL
#define SIZE_4MB                0x00400000UL
#define SIZE_8MB                0x00800000UL
#define SIZE_16MB               0x01000000UL
#define SIZE_32MB               0x02000000UL
#define SIZE_64MB               0x04000000UL
#define SIZE_128MB              0x08000000UL
#define SIZE_256MB              0x10000000UL
#define SIZE_512MB              0x20000000UL
#define SIZE_1GB                0x40000000UL
#define SIZE_2GB                0x80000000UL
#define SIZE_4GB                0x0000000100000000ULL
#define SIZE_8GB                0x0000000200000000ULL
#define SIZE_16GB               0x0000000400000000ULL
#define SIZE_32GB               0x0000000800000000ULL
#define SIZE_64GB               0x0000001000000000ULL
#define SIZE_128GB              0x0000002000000000ULL
#define SIZE_256GB              0x0000004000000000ULL
#define SIZE_512GB              0x0000008000000000ULL
#define SIZE_1TB                0x0000010000000000ULL
#define SIZE_2TB                0x0000020000000000ULL
#define SIZE_4TB                0x0000040000000000ULL
#define SIZE_8TB                0x0000080000000000ULL
#define SIZE_16TB               0x0000100000000000ULL
#define SIZE_32TB               0x0000200000000000ULL
#define SIZE_64TB               0x0000400000000000ULL
#define SIZE_128TB              0x0000800000000000ULL
#define SIZE_256TB              0x0001000000000000ULL
#define SIZE_512TB              0x0002000000000000ULL
#define SIZE_1PB                0x0004000000000000ULL
#define SIZE_2PB                0x0008000000000000ULL
#define SIZE_4PB                0x0010000000000000ULL
#define SIZE_8PB                0x0020000000000000ULL
#define SIZE_16PB               0x0040000000000000ULL
#define SIZE_32PB               0x0080000000000000ULL
#define SIZE_64PB               0x0100000000000000ULL
#define SIZE_128PB              0x0200000000000000ULL
#define SIZE_256PB              0x0400000000000000ULL
#define SIZE_512PB              0x0800000000000000ULL
#define SIZE_1EB                0x1000000000000000ULL
#define SIZE_2EB                0x2000000000000000ULL
#define SIZE_4EB                0x4000000000000000ULL
#define SIZE_8EB                0x8000000000000000ULL


/** bit(s) mask */
#define BM1                     0x00000001UL
#define BM2                     0x00000003UL
#define BM3                     0x00000007UL
#define BM4                     0x0000000FUL
#define BM5                     0x0000001FUL
#define BM6                     0x0000003FUL
#define BM7                     0x0000007FUL
#define BM8                     0x000000FFUL
#define BM9                     0x000001FFUL
#define BM10                    0x000003FFUL
#define BM11                    0x000007FFUL
#define BM12                    0x00000FFFUL
#define BM13                    0x00001FFFUL
#define BM14                    0x00003FFFUL
#define BM15                    0x00007FFFUL
#define BM16                    0x0000FFFFUL
#define BM17                    0x0001FFFFUL
#define BM18                    0x0003FFFFUL
#define BM19                    0x0007FFFFUL
#define BM20                    0x000FFFFFUL
#define BM21                    0x001FFFFFUL
#define BM22                    0x003FFFFFUL
#define BM23                    0x007FFFFFUL
#define BM24                    0x00FFFFFFUL
#define BM25                    0x01FFFFFFUL
#define BM26                    0x03FFFFFFUL
#define BM27                    0x07FFFFFFUL
#define BM28                    0x0FFFFFFFUL
#define BM29                    0x1FFFFFFFUL
#define BM30                    0x3FFFFFFFUL
#define BM31                    0x7FFFFFFFUL
#define BM32                    0xFFFFFFFFUL
#define BM33                    0x00000001FFFFFFFFULL
#define BM34                    0x00000003FFFFFFFFULL
#define BM35                    0x00000007FFFFFFFFULL
#define BM36                    0x0000000FFFFFFFFFULL
#define BM37                    0x0000001FFFFFFFFFULL
#define BM38                    0x0000003FFFFFFFFFULL
#define BM39                    0x0000007FFFFFFFFFULL
#define BM40                    0x000000FFFFFFFFFFULL
#define BM41                    0x000001FFFFFFFFFFULL
#define BM42                    0x000003FFFFFFFFFFULL
#define BM43                    0x000007FFFFFFFFFFULL
#define BM44                    0x00000FFFFFFFFFFFULL
#define BM45                    0x00001FFFFFFFFFFFULL
#define BM46                    0x00003FFFFFFFFFFFULL
#define BM47                    0x00007FFFFFFFFFFFULL
#define BM48                    0x0000FFFFFFFFFFFFULL
#define BM49                    0x0001FFFFFFFFFFFFULL
#define BM50                    0x0003FFFFFFFFFFFFULL
#define BM51                    0x0007FFFFFFFFFFFFULL
#define BM52                    0x000FFFFFFFFFFFFFULL
#define BM53                    0x001FFFFFFFFFFFFFULL
#define BM54                    0x003FFFFFFFFFFFFFULL
#define BM55                    0x007FFFFFFFFFFFFFULL
#define BM56                    0x00FFFFFFFFFFFFFFULL
#define BM57                    0x01FFFFFFFFFFFFFFULL
#define BM58                    0x03FFFFFFFFFFFFFFULL
#define BM59                    0x07FFFFFFFFFFFFFFULL
#define BM60                    0x0FFFFFFFFFFFFFFFULL
#define BM61                    0x1FFFFFFFFFFFFFFFULL
#define BM62                    0x3FFFFFFFFFFFFFFFULL
#define BM63                    0x7FFFFFFFFFFFFFFFULL
#define BM64                    0xFFFFFFFFFFFFFFFFULL

/** bit(s) mask (zero) */
#define BMZ1                    0xFFFFFFFFFFFFFFFEULL
#define BMZ2                    0xFFFFFFFFFFFFFFFCULL
#define BMZ3                    0xFFFFFFFFFFFFFFF8ULL
#define BMZ4                    0xFFFFFFFFFFFFFFF0ULL
#define BMZ5                    0xFFFFFFFFFFFFFFE0ULL
#define BMZ6                    0xFFFFFFFFFFFFFFC0ULL
#define BMZ7                    0xFFFFFFFFFFFFFF80ULL
#define BMZ8                    0xFFFFFFFFFFFFFF00ULL
#define BMZ9                    0xFFFFFFFFFFFFFE00ULL
#define BMZ10                   0xFFFFFFFFFFFFFC00ULL
#define BMZ11                   0xFFFFFFFFFFFFF800ULL
#define BMZ12                   0xFFFFFFFFFFFFF000ULL
#define BMZ13                   0xFFFFFFFFFFFFE000ULL
#define BMZ14                   0xFFFFFFFFFFFFC000ULL
#define BMZ15                   0xFFFFFFFFFFFF8000ULL
#define BMZ16                   0xFFFFFFFFFFFF0000ULL
#define BMZ17                   0xFFFFFFFFFFFE0000ULL
#define BMZ18                   0xFFFFFFFFFFFC0000ULL
#define BMZ19                   0xFFFFFFFFFFF80000ULL
#define BMZ20                   0xFFFFFFFFFFF00000ULL
#define BMZ21                   0xFFFFFFFFFFE00000ULL
#define BMZ22                   0xFFFFFFFFFFC00000ULL
#define BMZ23                   0xFFFFFFFFFF800000ULL
#define BMZ24                   0xFFFFFFFFFF000000ULL
#define BMZ25                   0xFFFFFFFFFE000000ULL
#define BMZ26                   0xFFFFFFFFFC000000ULL
#define BMZ27                   0xFFFFFFFFF8000000ULL
#define BMZ28                   0xFFFFFFFFF0000000ULL
#define BMZ29                   0xFFFFFFFFE0000000ULL
#define BMZ30                   0xFFFFFFFFC0000000ULL
#define BMZ31                   0xFFFFFFFF80000000ULL
#define BMZ32                   0xFFFFFFFF00000000ULL
#define BMZ33                   0xFFFFFFFE00000000ULL
#define BMZ34                   0xFFFFFFFC00000000ULL
#define BMZ35                   0xFFFFFFF800000000ULL
#define BMZ36                   0xFFFFFFF000000000ULL
#define BMZ37                   0xFFFFFFE000000000ULL
#define BMZ38                   0xFFFFFFC000000000ULL
#define BMZ39                   0xFFFFFF8000000000ULL
#define BMZ40                   0xFFFFFF0000000000ULL
#define BMZ41                   0xFFFFFE0000000000ULL
#define BMZ42                   0xFFFFFC0000000000ULL
#define BMZ43                   0xFFFFF80000000000ULL
#define BMZ44                   0xFFFFF00000000000ULL
#define BMZ45                   0xFFFFE00000000000ULL
#define BMZ46                   0xFFFFC00000000000ULL
#define BMZ47                   0xFFFF800000000000ULL
#define BMZ48                   0xFFFF000000000000ULL
#define BMZ49                   0xFFFE000000000000ULL
#define BMZ50                   0xFFFC000000000000ULL
#define BMZ51                   0xFFF8000000000000ULL
#define BMZ52                   0xFFF0000000000000ULL
#define BMZ53                   0xFFE0000000000000ULL
#define BMZ54                   0xFFC0000000000000ULL
#define BMZ55                   0xFF80000000000000ULL
#define BMZ56                   0xFF00000000000000ULL
#define BMZ57                   0xFE00000000000000ULL
#define BMZ58                   0xFC00000000000000ULL
#define BMZ59                   0xF800000000000000ULL
#define BMZ60                   0xF000000000000000ULL
#define BMZ61                   0xE000000000000000ULL
#define BMZ62                   0xC000000000000000ULL
#define BMZ63                   0x8000000000000000ULL
#define BMZ64                   0x0000000000000000ULL


/** bit(s) operation */
/**
 *                                |n|        0|
 * +------------------------------+-+---------+
 * |                              |/|         |
 * +------------------------------+-+---------+
 *                              BIT_MSK(n)
 */
#define BIT_MSK(n)              (1ULL << (n))
#define BIT_SET(var, n)         {var |=  BIT_MSK(n);}
#define BIT_CLR(var, n)         {var &= ~BIT_MSK(n);}
#define BIT_REV(var, n)         {var ^=  BIT_MSK(n);}

/* @brief -- test a bit.
 * If the bit is one then the result will be TRUE, otherwise FALSE.
 */
#define BIT_TST(val, n)         (((val) & BIT_MSK(n)) != 0)

/**
 *                                 n|        0|
 * +--------------------------------+---------+
 * |                                |/////////|
 * +--------------------------------+---------+
 *                                   BITS_MSK(n)
 *
 *                  |m             n|        0|
 * +----------------+---------------+---------+
 * |                |///////////////|         |
 * +----------------+---------------+---------+
 *                    BITS_MSK2(m,n)  {m >= n}
 */
#define BITS_MSK(n)             ((1ULL << (n)) - 1ULL)
#define BITS_MSK2(m, n)         (BITS_MSK((m) - (n) + 1ULL) << (n))
#define BITS_SET(var, mask)     {var |=  (mask);}
#define BITS_CLR(var, mask)     {var &= ~(mask);}
#define BITS_REV(var, mask)     {var ^=  (mask);}

/* @brief -- extract the specified field value. The result is the field value.
 * @pos field position
 * @bw  field bitwidth
 */
#define BITF_GET(data, pos, bw)      (((data) >> (pos)) & BITS_MSK(bw))

/* @brief -- override the specified field using the param named as value.
 * @pos field position
 * @bw  field bitwidth
 * @val field value to be written
 */
#define BITF_SET(data, pos, bw, val) (((data) & ~(BITS_MSK(bw) << (pos))) | (((val) & BITS_MSK(bw)) << (pos)))


/**
 * calculate bits shift count by idx
 *
 *  31 29     20 19     10 9       0
 * +--+---------+---------+---------+
 * |  |/////////|/////////|/////////|   BITSC_LSB32(i, bw)
 * +--+---------+---------+---------+
 *          0         1         2  (idx)
 *          0 << 20 = 2*10 = (32/10 - 1) * 10
 *          1 << 10 = 1*10 = (32/10 - 2) * 10
 *          2 <<  0 = 0*10 = (32/10 - 3) * 10
 *          i << ?? = (32/bw - (i+1)) * bw = (32/bw - 1 - i) * bw
 *
 *  31     22 21     12 11      2  0
 * +---------+---------+---------+--+
 * |/////////|/////////|/////////|  |   BITSC_MSB32(i, bw)
 * +---------+---------+---------+--+
 *    0         1         2        (idx)
 *    0 << 22 = 32 - 1*10
 *    1 << 12 = 32 - 2*10
 *    2 <<  2 = 32 - 3*10
 *    i << ?? = 32 - (i+1)*bw = 32 - bw - i*bw
 */
#define BITSC_LSB32(i, bw)      ((32/(bw) - 1 - (i)) * (bw))
#define BITSC_MSB32(i, bw)      (32 - (bw) - (i)*(bw))




/***********************************************************************************************************************
 * used frequently macros
 **********************************************************************************************************************/
#define ARRAY_ELEMENTS(a)       (sizeof(a) / sizeof(a[0]))


#define MIN(x, y)               (((x) <= (y)) ? (x) : (y))
#define MAX(x, y)               (((x) >= (y)) ? (x) : (y))


#define WRAP_INC(var, max)      do{var = var + 1 < (max) ? var + 1 : 0;        }while(0)
#define WRAP_DEC(var, max)      do{var = var     > 0     ? var - 1 : (max) - 1;}while(0)
#define WRAP_ADD(var, val, max) do{var = var <  (max) - (val) ? var + (val) : var   - ((max) - (val));}while(0)
#define WRAP_SUB(var, val, max) do{var = var >=         (val) ? var - (val) : (max) -  (val) + var;   }while(0)
#define WRAP_ADD_SAFE(var, val, max)    do{ \
                                            if((val) <= (max))  WRAP_ADD(var, val, max); \
                                            else                WRAP_ADD(var, (val)%(max), max); \
                                        }}while(0)
#define WRAP_SUB_SAFE(var, val, max)    do{ \
                                            if((val) <= (max))  WRAP_SUB(var, val, max); \
                                            else                WRAP_SUB(var, (val)%(max), max); \
                                        }}while(0)



/** register read/write */
#define REG8(reg_addr)          (*(volatile unsigned char      *)(reg_addr))
#define REG16(reg_addr)         (*(volatile unsigned short     *)(reg_addr))
#define REG32(reg_addr)         (*(volatile unsigned int       *)(reg_addr))
#define REG64(reg_addr)         (*(volatile unsigned long long *)(reg_addr))


/** align operations */
/** n must be power of 2 */
#define IS_POWEROF_2(n)         ( (((n) & ~(n)) == 0))
#define ALIGN_UP(x, n)          ( (((n) - 1ULL) + (x)) & ~((n) - 1ULL))
#define ALIGN_DN(x, n)          ( (               (x)) & ~((n) - 1ULL))
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


#ifndef USE_STDDEF_H
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member.
 * @type:   the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 */
#define offsetof(type, member)                  ((size_t)&((type*)0)->member)
#define container_of(ptr, type, member)         ((type*)((char*)(ptr) - offsetof(type, member)))
#endif

/** for_each_* */
#define for_each_array(p, a)                    for(p = a;    p < a + ARRAY_ELEMENTS(a);              (p)++)
#define for_each_array_p(i, p, a)               for(p = a, i = 0; i < ARRAY_ELEMENTS(a);              (p)++, (i)++)
#define for_each_array_e(i, e, a)               for(       i = 0; i < ARRAY_ELEMENTS(a) && (e = a[i], TRUE); (i)++)
#define for_each_table(p, t, n)                 for(p = t;    p < t + (n);                (p)++)
#define for_each_table_p(i, p, t, n)            for(p = t, i = 0; i < (n);                (p)++, (i)++)
#define for_each_table_e(i, e, t, n)            for(       i = 0; i < (n) && (e = (t)[i], TRUE); (i)++)
#define for_each_tabnn(p, t)                    for(p = t;        ;            (p)++)
#define for_each_tabnn_p(i, p, t)               for(p = t, i = 0; ;            (p)++, (i)++)
#define for_each_tabnn_e(i, e, t)               for(       i = 0; (e = (t)[i], TRUE); (i)++)
#define for_each_seq(i, base, top)              for(i = base; i < top; (i)++)





#endif /* LATMACROS_H_ */

