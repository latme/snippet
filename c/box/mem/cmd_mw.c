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
  mw addr unit_size unit_value\n\
\n\
  valid unit_size is one of 1,2,4,8;\n\
  a prefix '0x' is needed when unit_value is a hexadecimal.\n\
");
}


static int mem_mw_main(int argc, char *argv[])
{
    unsigned int        unit_size = 0;
    unsigned long long  unit_value  = 0;
    bool                endian_swap = FALSE;
    struct mem_map      mem;
    unsigned long long  phyaddr;
    void                *viraddr;
    char                *arg;
    char                *ptr;


    if(argc != 4)
    {
        mem_mw_usage();
        return -1;
    }

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

    ///< write memory
    viraddr = mem.map_virbase + mem.map_ofst;
    mem_mw(viraddr, phyaddr, unit_size, unit_value, endian_swap);

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

