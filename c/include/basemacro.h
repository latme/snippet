/*
 * filename: basemacro.h
 */


#ifndef BASEMACRO_H_
#define BASEMACRO_H_



#define MIN(x, y)               (((x) <= (y)) ? (x) : (y))
#define MAX(x, y)               (((x) >= (y)) ? (x) : (y))




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



#endif /* BASEMACRO_H_ */

