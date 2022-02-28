#include <latbox/mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/io.h>





static int mem_iow_usage(void)
{
    printf("\n\
usage:\n\
  iow addr unit_size unit_value [mask [l_shift]]\n\
\n\
  valid unit_size is one of 1,2,4;\n\
  a prefix '0x' is needed when unit_value is a hexadecimal.\n\
");
}


static int mem_iow_main(int argc, char *argv[])
{
    int                 err;
    unsigned int        unit_size = 0;
    unsigned int        unit_value  = 0;
    unsigned int        unit_mask  = 0;
    unsigned int        unit_shift = 0;
    unsigned int        unit_tmp;
    bool                endian_swap = FALSE;
    unsigned int        phyaddr;
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
        unit_mask  = strtoul(arg, &ptr, 0);
        if (arg == ptr) {
            printf( "mask (%s) is not a number\n", arg);
            return -1;
        }
        /* fall-through */
    case 4:
        arg = argv[3];
        unit_value = strtoul(arg, &ptr, 0);
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
        } else if (phyaddr > 0xffff) {
            printf("addr (%s) over 64KB\n", arg);
            return -3;
        }
        break;

    defualt:
        mem_iow_usage();
        return -1;
    }

    if(strncmp(argv[0], "iowl", 3) == 0)
    {
        endian_swap = mem_core_is_little_endian() ? FALSE : TRUE;
    }
    else if(strncmp(argv[0], "iowb", 3) == 0)
    {
        endian_swap = mem_core_is_little_endian() ? TRUE : FALSE;
    }


    ///< request access permission
    err = ioperm(0, SIZE_64KB, 1);
    if (err < 0) {
        perror("request io permission fail!");
        return -1;
    }

    unit_value <<= unit_shift;
    unit_mask  <<= unit_shift;

    ///< write i/o space
    switch (unit_size) {
    case 4:
        if (unit_mask != 0) {
            unit_tmp = inl(phyaddr);
            if (endian_swap) {
                unit_tmp = ENDIAN_SWAP32(unit_tmp);
            }

            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        printf("%04x = %08x\n", phyaddr, unit_value);
        if (endian_swap) {
            unit_value = ENDIAN_SWAP32(unit_value);
        }

        outl(unit_value, phyaddr);
        break;

    case 2:
        if (unit_mask != 0) {
            unit_tmp = inw(phyaddr);
            if (endian_swap) {
                unit_tmp = ENDIAN_SWAP16(unit_tmp);
            }

            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        printf("%04x = %04x\n", phyaddr, unit_value);
        if (endian_swap) {
            unit_value = ENDIAN_SWAP16(unit_value);
        }

        outw(unit_value, phyaddr);
        break;

    case 1:
        if (unit_mask != 0) {
            unit_tmp = inb(phyaddr);
            unit_value = (unit_tmp & ~unit_mask) | (unit_value & unit_mask);
        }

        printf("%04x = %02x\n", phyaddr, unit_value);
        outb(unit_value, phyaddr);
        break;

    default:
        printf("unit_size must be one of 1,2,4\n");
    }

    return 0;
}


void mem_iow_register(void)
{
    main_register_appcmd("iow",  "I/O Write", NULL, mem_iow_main);
    main_register_appcmd("iowl", "I/O Write with little-endian", NULL, mem_iow_main);
    main_register_appcmd("iowb", "I/O Write with big-endian",    NULL, mem_iow_main);
}

