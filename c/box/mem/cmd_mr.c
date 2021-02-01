#include <latbox/init.h>
#include <latbox/mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>




static int mem_mr_usage(void)
{
    printf("\n\
usage:\n\
  mr addr [unit_size [unit_num]]\n\
\n\
  valid unit_size is one of 1,2,4,8, default unit_size is 4 (4Byte);\n\
  default unit_num  is 256/unit_size.\n\
");
}


static int mem_mr_main(int argc, char *argv[])
{
    unsigned int        unit_size = 0;
    unsigned int        unit_num  = 0;
    bool                endian_swap = FALSE;
    struct mem_map      mem;
    unsigned long long  phyaddr;
    void                *viraddr;
    char                *arg;
    char                *ptr;


    switch (argc)
    {
    case 4:
        arg = argv[3];
        unit_num = strtoul(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "unit_num (%s) is not a number\n", arg);
            return -2;
        }
        /* fall-through */
    case 3:
        arg = argv[2];
        unit_size = strtoul(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "unit_size (%s) is not a number\n", arg);
            return -2;
        }
        /* fall-through */
    case 2:
        arg = argv[1];
        phyaddr = strtoull(arg, &ptr, 16);
        if (arg == ptr) {
            printf( "addr (%s) is not a number\n", arg);
            return -2;
        }

        if(strncmp(argv[0], "mrl", 3) == 0)
        {
            endian_swap = mem_core_is_little_endian() ? FALSE : TRUE;
        }
        else if(strncmp(argv[0], "mrb", 3) == 0)
        {
            endian_swap = mem_core_is_little_endian() ? TRUE : FALSE;
        }

        unit_size = (unit_size > 0) ? unit_size : 4;
        unit_num  = (unit_num  > 0) ? unit_num  : 256 / unit_size;
        break;
    
    default:
        mem_mr_usage();
        return -1;
    }


    mem_map_align(phyaddr, unit_size*unit_num, &mem);

    ///< memory map
    mem.mem_fd= open("/dev/mem", O_RDONLY);
    if (mem.mem_fd < 0) {
        perror("open /dev/mem failed");
        return -3;
    }

    mem.map_virbase = mmap(NULL, mem.map_len, PROT_READ, MAP_SHARED,
                                 mem.mem_fd, mem.map_phybase);
    if (mem.map_virbase == MAP_FAILED) {
        perror("mmap failed");
        close(mem.mem_fd);
        return -4;
    }

    ///< read and show memory
    viraddr = mem.map_virbase + mem.map_ofst;
    mem_mr(viraddr, phyaddr, unit_size, unit_num, endian_swap);

    ///< memory unmap
    munmap(mem.map_virbase, mem.map_len);
    close(mem.mem_fd);

    return 0;
}


void mem_mr_register(void)
{
    main_register_appcmd("mr",  "Memory Read", NULL, mem_mr_main);
    main_register_appcmd("mrl", "Memory Read with little-endian", NULL, mem_mr_main);
    main_register_appcmd("mrb", "Memory Read with big-endian",   NULL, mem_mr_main);
}
