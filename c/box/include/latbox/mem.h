#ifndef __LATBOX_MEM_H__
#define __LATBOX_MEM_H__

#include <latbox/init.h>


struct mem_map {
    unsigned long long  map_phybase;
    size_t              map_ofst;
    size_t              map_len;

    int                 mem_fd;
    char               *map_virbase;
};





bool mem_core_is_little_endian(void);
void mem_mr(void *addr, unsigned long long show_addr,
            unsigned int unit_size, unsigned int unit_num, bool swap_endian);
void mem_mw(void *addr, unsigned long long show_addr,
            unsigned int unit_size, unsigned long long unit_value, bool swap_endian);


void mem_map_align(unsigned long long phyaddr, size_t size, struct mem_map *mem);


#endif  ///< __LATBOX_MEM_H__
