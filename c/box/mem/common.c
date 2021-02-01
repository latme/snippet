#include <latbox/mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


bool mem_core_is_little_endian(void)
{
    unsigned int data = 0xFF;

    return (*(unsigned char*)&data == 0xFF);
}


/* Memory Read */
void mem_mr(void *addr, unsigned long long show_addr,
            unsigned int unit_size, unsigned int unit_num, bool swap_endian)
{
    unsigned char       *p_byte;
    unsigned short      *p_word;
    unsigned int        *p_dword;
    unsigned long long  *p_qword;
    unsigned short      word;
    unsigned int        dword;
    unsigned long long  qword;
    unsigned int        unit_idx;
    unsigned int        col = 0;


    // printf("%s  %p %u %u\n", __FUNCTION__, addr, unit_size, unit_num);

    switch(unit_size)
    {
    case 8:
        p_qword = (unsigned long long *)addr;
        for(unit_idx = 0; unit_idx < unit_num; unit_idx++)
        {
            if(col == 0)
            {
                printf("%016llx:", (show_addr + unit_idx * unit_size));
            }

            qword = p_qword[unit_idx];
            qword = swap_endian ? ENDIAN_SWAP64(qword) : qword;
            printf(" %016llx", qword);

            col += unit_size;
            if(col >= 16)
            {
                col = 0;
                printf("\n");
            }
        }
        break;

    case 4:
        p_dword = (unsigned int *)addr;
        for(unit_idx = 0; unit_idx < unit_num; unit_idx++)
        {
            if(col == 0)
            {
                printf("%016llx:", (show_addr + unit_idx * unit_size));
            }

            dword = p_dword[unit_idx];
            dword = swap_endian ? ENDIAN_SWAP32(dword) : dword;
            printf(" %08x", dword);

            col += unit_size;
            if(col >= 16)
            {
                col = 0;
                printf("\n");
            }
        }
        break;

    case 2:
        p_word = (unsigned short *)addr;
        for(unit_idx = 0; unit_idx < unit_num; unit_idx++)
        {
            if(col == 0)
            {
                printf("%016llx:", (show_addr + unit_idx * unit_size));
            }

            word = p_word[unit_idx];
            word = swap_endian ? ENDIAN_SWAP16(word) : word;
            printf(" %04x", word);

            col += unit_size;
            if(col == 8)
            {
                printf(" ");
            }
            else if(col >= 16)
            {
                col = 0;
                printf("\n");
            }
        }
        break;

    case 1:
        p_byte = (unsigned char *)addr;
        for(unit_idx = 0; unit_idx < unit_num; unit_idx++)
        {
            if(col == 0)
            {
                printf("%016llx:", (show_addr + unit_idx * unit_size));
            }

            printf(" %02x", p_byte[unit_idx]);

            col += unit_size;
            if(col == 8)
            {
                printf(" ");
            }
            else if(col >= 16)
            {
                col = 0;
                printf("\n");
            }
        }
        break;
    
    default:
        printf("unit_size must be one of 1,2,4,8\n");
        return;
    }

    if(col > 0)
    {
        printf("\n");
    }
}


/* Memory Write */
void mem_mw(void *addr, unsigned long long show_addr,
            unsigned int unit_size, unsigned long long unit_value, bool swap_endian)
{
    // printf("%s  %p %u 0x%llx\n", __FUNCTION__, addr, unit_size, unit_value);

    switch(unit_size)
    {
    case 8:
        *(unsigned long long *)addr = swap_endian ? ENDIAN_SWAP64(unit_value) : unit_value;
        break;
    case 4:
        unit_value = (unsigned int)unit_value;
        *(unsigned int       *)addr = swap_endian ? ENDIAN_SWAP32(unit_value) : unit_value;
        break;
    case 2:
        unit_value = (unsigned short)unit_value;
        *(unsigned short     *)addr = swap_endian ? ENDIAN_SWAP16(unit_value) : unit_value;
        break;
    case 1:
        unit_value = (unsigned char)unit_value;
        *(unsigned char      *)addr = unit_value;
        break;
    default:
        printf("unit_size must be one of 1,2,4,8\n");
        return;
    }

    printf("%016llx = 0x%llx\n", show_addr, unit_value);
}


void mem_map_align(unsigned long long phyaddr, size_t size, struct mem_mmap *mem)
{
    long    page_size;

    page_size = sysconf(_SC_PAGESIZE);
    mem->map_phybase = ALIGN_DN(phyaddr, page_size);
    mem->map_ofst    = (phyaddr - mem->map_phybase);
    mem->map_len     = ALIGN_UP(mem->map_ofst + size, page_size);
}


