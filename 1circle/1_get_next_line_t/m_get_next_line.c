#include <stdio.h>
#include "../gnl/get_next_line.h"

int main(void)
{
    char *fname;
    char *fname2;
    char *result;
    //char *cmp;
    int fd;
    int fd2;
    int i = 1;

    fname = "./test.txt";
    fname2 = "./test.txt";
    fd = open(fname, O_RDWR);
	printf("fd : %d\n", fd);
    fd2 = open(fname2, O_RDWR);
	printf("fd2 : %d\n", fd2);
    result = "1";
    while (result)
    {
        result = get_next_line(fd);
        printf("%d line : %s", i, result);
        i++;
    }
    /*cmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    cmp[BUFFER_SIZE] = 0;
    printf("\n\n");
    while ((read(fd2, cmp, BUFFER_SIZE)) > 0)
        printf("%s\n", cmp);*/
}
