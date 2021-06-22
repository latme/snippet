#include <fcntl.h>          // for open/close
#include <sys/ioctl.h>      // for ioctl
#include <stdio.h>          // for printf


#define DEVNAME  "/dev/latme_dev"




int main(int argc, char *argv[])
{
    int     fd;

    fd = open(DEVNAME, 0);
    if (fd < 0) {
        printf("open %s failed!\n", DEVNAME);
        return -1;
    }

    ioctl(fd, 0, 1);
    ioctl(fd, 1, 2);

    return 0;
}

