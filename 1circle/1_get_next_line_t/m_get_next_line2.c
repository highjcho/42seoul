#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *fname;
    char *fname2;
    char *result;
    char *cmp;
    int fd;
    int fd2;
    int BUFFER_SIZE;
    int i;

    fname = "./test.txt";
    fname2 = "./test.txt";
    fd = open(fname, O_RDWR);
    fd2 = open(fname2, O_RDWR);
    BUFFER_SIZE = 7;
    i = 0;
    result = "1";
    while (result)
    {
        result = get_next_line(fd, BUFFER_SIZE);
        printf("%s, %d\n", result, i);
        i++;
    }
    cmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    cmp[BUFFER_SIZE] = 0;
    printf("what\n\n");
    int j = 0;
    while ((read(fd2, cmp, BUFFER_SIZE)) > 0)
    {
        printf("%s\n", cmp);
        j++;
        printf("i check: %d\n", j);
    }
}
