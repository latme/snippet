#include <latbox/mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>





static int mem_mw_usage(void)
{
    printf("\n\
usage:\n\
  mw addr unit_size unit_value [mask [l_shift]]\n\
\n\
  valid unit_size is one of 1,2,4,8;\n\
  a prefix '0x' is needed when unit_value is a hexadecimal.\n\
");
}


static int mem_mw_main(int argc, char *argv[])
{
    unsigned int        unit_size = 0;
    unsigned int        unit_shift  = 0;
    unsigned long long  unit_mask   = 0;
    unsigned long long  unit_value  = 0;
    unsigned long long  unit_tmp;
    bool                endian_swap = FALSE;
    struct mem_map      mem;
    unsigned long long  phyaddr;
    void                *viraddr;
    char                *arg;
    char                *ptr;


    switch (argc) {
    case 6:
        arg = argv[5];
        unit_shift = strtoul(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "l_shift (%s) is not a number\n", arg);
            return -1;
        }
        /* fall-through */
    case 5:
        arg = argv[4];
        unit_mask  = strtoull(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "mask (%s) is not a number\n", arg);
            return -1;
        }
        /* fall-through */
    case 4:
        arg = argv[3];
        unit_value = strtoull(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "unit_value (%s) is not a number\n", arg);
            return -2;
        }

        arg = argv[2];
        unit_size = strtoul(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "unit_size (%s) is not a number\n", arg);
            return -2;
        }

        arg = argv[1];
        phyaddr = strtoul(arg, &ptr, 16);
        if (arg == ptr) {
            printf( "addr (%s) is not a number\n", arg);
            return -2;
        }
        break;

    default:
        mem_mw_usage();
        return -1;
    }

    if(strncmp(argv[0], "mwl", 3) == 0)
    {
        endian_swap = mem_core_is_little_endian() ? FALSE : TRUE;
    }
    else if(strncmp(argv[0], "mwb", 3) == 0)
    {
        endian_swap = mem_core_is_little_endian() ? TRUE : FALSE;
    }


    mem_map_align(phyaddr, unit_size, &mem);

    ///< memory map, why using O_WRONLY report "Permission denied"
    //mem.mem_fd = open("/dev/mem", O_WRONLY);
    mem.mem_fd = open("/dev/mem", O_RDWR);
    if (mem.mem_fd < 0) {
        perror("open /dev/mem failed");
        return -3;
    }

    mem.map_virbase = mmap(NULL, mem.map_len, PROT_WRITE, MAP_SHARED,
                                 mem.mem_fd, mem.map_phybase);
    if (mem.map_virbase == MAP_FAILED) {
        perror("mmap failed");
        close(mem.mem_fd);
        return -4;
    }

    unit_value <<= unit_shift;
    unit_mask  <<= unit_shift;

    ///< write memory
    viraddr = mem.map_virbase + mem.map_ofst;
    switch(unit_size)
    {
    case 8:
        if (unit_mask != 0) {
            unit_tmp = *(unsigned long long *)viraddr;
            if (endian_swap) {
                unit_tmp = ENDIAN_SWAP64(unit_tmp);
            }

            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        printf("%016llx = 0x%016llx\n", phyaddr, unit_value);

        if (endian_swap) {
            unit_value = ENDIAN_SWAP64(unit_value);
        }

        *(unsigned long long *)viraddr = unit_value;
        break;

    case 4:
        if (unit_mask != 0) {
            unit_tmp = *(unsigned int *)viraddr;
            if (endian_swap) {
                unit_tmp = ENDIAN_SWAP32(unit_tmp);
            }

            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        unit_value = (unsigned int)unit_value;
        printf("%016llx = 0x%08llx\n", phyaddr, unit_value);

        if (endian_swap) {
            unit_value = ENDIAN_SWAP32(unit_value);
        }

        *(unsigned int *)viraddr = unit_value;
        break;

    case 2:
        if (unit_mask != 0) {
            unit_tmp = *(unsigned short *)viraddr;
            if (endian_swap) {
                unit_tmp = ENDIAN_SWAP16(unit_tmp);
            }

            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        unit_value = (unsigned short)unit_value;
        printf("%016llx = 0x%04llx\n", phyaddr, unit_value);

        if (endian_swap) {
            unit_value = ENDIAN_SWAP16(unit_value);
        }

        *(unsigned short *)viraddr = unit_value;
        break;

    case 1:
        if (unit_mask != 0) {
            unit_tmp = *(unsigned char *)viraddr;
            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        unit_value = (unsigned char)unit_value;
        printf("%016llx = 0x%02llx\n", phyaddr, unit_value);

        *(unsigned char *)viraddr = unit_value;
        break;

    default:
        printf("unit_size must be one of 1,2,4,8\n");
        return -1;
    }

    ///< memory unmap
    munmap(mem.map_virbase, mem.map_len);
    close(mem.mem_fd);

    return 0;
}


void mem_mw_register(void)
{
    main_register_appcmd("mw",  "Memory Write", NULL, mem_mw_main);
    main_register_appcmd("mwl", "Memory Write with little-endian", NULL, mem_mw_main);
    main_register_appcmd("mwb", "Memory Write with big-endian",    NULL, mem_mw_main);
}

