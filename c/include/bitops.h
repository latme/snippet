/*
 * filename: bitops.h
 *
 */

#ifndef BITOPS_H_
#define BITOPS_H_


/** constant size */
#define SIZE_1B                 (size_t)0x00000001UL
#define SIZE_2B                 (size_t)0x00000002UL
#define SIZE_4B                 (size_t)0x00000004UL
#define SIZE_8B                 (size_t)0x00000008UL
#define SIZE_16B                (size_t)0x00000010UL
#define SIZE_32B                (size_t)0x00000020UL
#define SIZE_64B                (size_t)0x00000040UL
#define SIZE_128B               (size_t)0x00000080UL
#define SIZE_256B               (size_t)0x00000100UL
#define SIZE_512B               (size_t)0x00000200UL
#define SIZE_1KB                (size_t)0x00000400UL
#define SIZE_2KB                (size_t)0x00000800UL
#define SIZE_4KB                (size_t)0x00001000UL
#define SIZE_8KB                (size_t)0x00002000UL
#define SIZE_16KB               (size_t)0x00004000UL
#define SIZE_32KB               (size_t)0x00008000UL
#define SIZE_64KB               (size_t)0x00010000UL
#define SIZE_128KB              (size_t)0x00020000UL
#define SIZE_256KB              (size_t)0x00040000UL
#define SIZE_512KB              (size_t)0x00080000UL
#define SIZE_1MB                (size_t)0x00100000UL
#define SIZE_2MB                (size_t)0x00200000UL
#define SIZE_4MB                (size_t)0x00400000UL
#define SIZE_8MB                (size_t)0x00800000UL
#define SIZE_16MB               (size_t)0x01000000UL
#define SIZE_32MB               (size_t)0x02000000UL
#define SIZE_64MB               (size_t)0x04000000UL
#define SIZE_128MB              (size_t)0x08000000UL
#define SIZE_256MB              (size_t)0x10000000UL
#define SIZE_512MB              (size_t)0x20000000UL
#define SIZE_1GB                (size_t)0x40000000UL
#define SIZE_2GB                (size_t)0x80000000UL
#define SIZE_4GB                (size_t)0x0000000100000000ULL
#define SIZE_8GB                (size_t)0x0000000200000000ULL
#define SIZE_16GB               (size_t)0x0000000400000000ULL
#define SIZE_32GB               (size_t)0x0000000800000000ULL
#define SIZE_64GB               (size_t)0x0000001000000000ULL
#define SIZE_128GB              (size_t)0x0000002000000000ULL
#define SIZE_256GB              (size_t)0x0000004000000000ULL
#define SIZE_512GB              (size_t)0x0000008000000000ULL
#define SIZE_1TB                (size_t)0x0000010000000000ULL
#define SIZE_2TB                (size_t)0x0000020000000000ULL
#define SIZE_4TB                (size_t)0x0000040000000000ULL
#define SIZE_8TB                (size_t)0x0000080000000000ULL
#define SIZE_16TB               (size_t)0x0000100000000000ULL
#define SIZE_32TB               (size_t)0x0000200000000000ULL
#define SIZE_64TB               (size_t)0x0000400000000000ULL
#define SIZE_128TB              (size_t)0x0000800000000000ULL
#define SIZE_256TB              (size_t)0x0001000000000000ULL
#define SIZE_512TB              (size_t)0x0002000000000000ULL
#define SIZE_1PB                (size_t)0x0004000000000000ULL
#define SIZE_2PB                (size_t)0x0008000000000000ULL
#define SIZE_4PB                (size_t)0x0010000000000000ULL
#define SIZE_8PB                (size_t)0x0020000000000000ULL
#define SIZE_16PB               (size_t)0x0040000000000000ULL
#define SIZE_32PB               (size_t)0x0080000000000000ULL
#define SIZE_64PB               (size_t)0x0100000000000000ULL
#define SIZE_128PB              (size_t)0x0200000000000000ULL
#define SIZE_256PB              (size_t)0x0400000000000000ULL
#define SIZE_512PB              (size_t)0x0800000000000000ULL
#define SIZE_1EB                (size_t)0x1000000000000000ULL
#define SIZE_2EB                (size_t)0x2000000000000000ULL
#define SIZE_4EB                (size_t)0x4000000000000000ULL
#define SIZE_8EB                (size_t)0x8000000000000000ULL

/** bit(s) width */
#define BW1                     1U
#define BW2                     2U
#define BW3                     3U
#define BW4                     4U
#define BW5                     5U
#define BW6                     6U
#define BW7                     7U
#define BW8                     8U
#define BW9                     9U
#define BW10                    10U
#define BW11                    11U
#define BW12                    12U
#define BW13                    13U
#define BW14                    14U
#define BW15                    15U
#define BW16                    16U
#define BW17                    17U
#define BW18                    18U
#define BW19                    19U
#define BW20                    20U
#define BW21                    21U
#define BW22                    22U
#define BW23                    23U
#define BW24                    24U
#define BW25                    25U
#define BW26                    26U
#define BW27                    27U
#define BW28                    28U
#define BW29                    29U
#define BW30                    30U
#define BW31                    31U
#define BW32                    32U
#define BW33                    33U
#define BW34                    34U
#define BW35                    35U
#define BW36                    36U
#define BW37                    37U
#define BW38                    38U
#define BW39                    39U
#define BW40                    40U
#define BW41                    41U
#define BW42                    42U
#define BW43                    43U
#define BW44                    44U
#define BW45                    45U
#define BW46                    46U
#define BW47                    47U
#define BW48                    48U
#define BW49                    49U
#define BW50                    50U
#define BW51                    51U
#define BW52                    52U
#define BW53                    53U
#define BW54                    54U
#define BW55                    55U
#define BW56                    56U
#define BW57                    57U
#define BW58                    58U
#define BW59                    59U
#define BW60                    60U
#define BW61                    61U
#define BW62                    62U
#define BW63                    63U
#define BW64                    64U

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
 *                            |n             0|
 * +--------------------------+---------------+
 * |                          |///////////////|
 * +--------------------------+---------------+
 *                              BITS_MSK(m)
 *
 *                  |m             n|        0|
 * +----------------+---------------+---------+
 * |                |///////////////|         |
 * +----------------+---------------+---------+
 *                    BITS_MSK2(m,n)  {m >= n}
 */
#define BITS_MSK(m)             ((1ULL << ((m) + 1ULL)) - 1ULL)
#define BITS_MSK2(m, n)         (BITS_MSK((m) - (n)) << (n))
#define BITS_SET(var, mask)     {var |=  (mask);}
#define BITS_CLR(var, mask)     {var &= ~(mask);}
#define BITS_REV(var, mask)     {var ^=  (mask);}

/* @brief -- extract the specified field value. The result is the field value.
 * @pos field position
 * @bw  field bitwidth
 */
#define BITS_EXTRACT(val, pos, bw)  (((val) >> (pos)) & BITS_MSK(bw))

/* @brief -- override the specified field using the param named as value.
 * @pos field position
 * @bw  field bitwidth
 * @val field value to be written
 */
#define BITS_OVERRIDE(var, pos, bw, val)    \
        {var = (var & ~(BITS_MSK(bw) << (pos))) | ((val) << (pos));}


#endif /* BITOPS_H_ */

