#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char *fname;
    char buf[10];

    int fd;
    int read_result;

    fname = "./test.txt";

    fd = open(fname, O_RDWR);
    read_result = read(fd, buf, -5);
    printf("read result : %d", read_result);
}
    