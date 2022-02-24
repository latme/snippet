#include <latbox/init.h>
#include <latbox/mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/io.h>




static int mem_ior_usage(void)
{
    printf("\n\
usage:\n\
  ior addr [unit_size [unit_num]]\n\
\n\
  valid unit_size is one of 1,2,4, default unit_size is 4 (4Byte);\n\
  default unit_num  is 1.\n\
");
}


static int mem_ior_main(int argc, char *argv[])
{
    int                 err;
    unsigned int        unit_size = 0;
    unsigned int        unit_num  = 0;
    unsigned int        unit_val;
    bool                endian_swap = FALSE;
    unsigned int        phyaddr;
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
        phyaddr = strtoul(arg, &ptr, 16);
        if (arg == ptr) {
            printf( "addr (%s) is not a number\n", arg);
            return -2;
        } else if (phyaddr > 0xffff) {
            printf("addr (%s) over 64KB\n", arg);
            return -3;
        }

        if(strncmp(argv[0], "iorl", 3) == 0)
        {
            endian_swap = mem_core_is_little_endian() ? FALSE : TRUE;
        }
        else if(strncmp(argv[0], "iorb", 3) == 0)
        {
            endian_swap = mem_core_is_little_endian() ? TRUE : FALSE;
        }

        unit_size = (unit_size > 0) ? unit_size : 4;
        unit_num  = (unit_num  > 0) ? unit_num  : 1;
        break;

    default:
        mem_ior_usage();
        return -1;
    }


    ///< request access permission
    err = ioperm(0, SIZE_64KB, 1);
    if (err < 0) {
        perror("request io permission fail!");
        return -1;
    }

    ///< read and show i/o space
    switch (unit_size) {
    case 4:
        while (unit_num--) {
            unit_val = inl_p(phyaddr);
            unit_val = endian_swap ? ENDIAN_SWAP32(unit_val) : unit_val;
            printf("%04x: %08x\n", phyaddr, unit_val);

            phyaddr += 4;
        }
        break;
    case 2:
        while (unit_num--) {
            unit_val = inw(phyaddr);
            unit_val = endian_swap ? ENDIAN_SWAP16(unit_val) : unit_val;
            printf("%04x: %04x\n", phyaddr, unit_val);

            phyaddr += 2;
        }
        break;
    case 1:
        while (unit_num--) {
            unit_val = inb(phyaddr);
            printf("%04x: %02x\n", phyaddr, unit_val);

            phyaddr += 1;
        }
        break;
    default:
        printf("unit_size must be one of 1,2,4\n");
    }

    return 0;
}


void mem_ior_register(void)
{
    main_register_appcmd("ior",  "I/O Read", NULL, mem_ior_main);
    main_register_appcmd("iorl", "I/O Read with little-endian", NULL, mem_ior_main);
    main_register_appcmd("iorb", "I/O Read with big-endian",    NULL, mem_ior_main);
}

