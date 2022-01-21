#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

size_t ft_len(char *s)
{
    size_t i;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\n')
        i++;
    return (i);
}

void ft_strncpy(char *dst, char *src, size_t len)
{
    while (len-- > 0)
        *dst++ = *src++;
}

void ft_memmove(char *dst, char *src, int n)
{
    while (n-- > 0)
        *(unsigned char *)dst++ = *(unsigned char *)src++;
}

void ft_bzero(char *s, int n)
{
    while (n-- > 0)
        *(unsigned char *)s++ = 0;
}

char *ft_calloc(size_t count, size_t size)
{
    char *new;

    new = (char *)malloc(count * size);
    if (!new)
        return (0);
    ft_bzero(new, count * size);
    return (new);
}

char *ft_strchr(char *s)
{
    while (*s)
    {
        if (*s == '\n')
            return (s);
        s++;
    }
    return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *new_result;
    size_t  s1_len;
    size_t  s2_len;
    //size_t i;
    //size_t j;

    s1_len = ft_len(s1);
    s2_len = ft_len(s2);
    new_result = ft_calloc((s1_len + s2_len + 1), sizeof(char));
    if (!new_result)
        return (0);
    //i = -1;
    while (s1_len-- > 1)
        *new_result++ = *s1++; // ㅇㅣ렇게는 왜 안됨?
    //j = -1;
    while (s2_len-- > 1)
        *new_result++ = *s2++;
    return (new_result);
}

char *make_line(char *buf, char *result)
{
    char *tmp;
    char *new_result;
    size_t len;

    len = ft_len(buf);
    tmp = ft_calloc((len + 1), sizeof(char));
    if (!tmp)
        return (0);
    ft_strncpy(tmp, buf, len);
    new_result = ft_strjoin(result, tmp);
    ft_memmove(buf, buf + len, BUFFER_SIZE - len);
    ft_bzero(buf + BUFFER_SIZE - len, len);
    free(tmp);
    free(result);
    return (new_result);
}

char *get_next_line(int fd)
{
    char *result;
    int read_result;
    static char buf[BUFFER_SIZE + 1];

    result = ft_calloc(1, sizeof(char));
    if (!result)
        return (0);
    while (!ft_strchr(result))
    {
        if (buf[0] == 0)
        {
            read_result = read(fd, buf, BUFFER_SIZE);
            if (!read_result && result[0] != 0)
                return (result);
            else if (read_result < 0 || (!read_result && result[0] == 0))
            {
                free(result);
                return (0);
            }
        }
        result = make_line(buf, result);
    }
    return (result);
}

int main(void)
{
    int fd;
    char *result;

    fd = open("./test.txt", O_RDWR);
    result = "1";
    while (result)
    {
        result = get_next_line(fd);
        printf("%s", result);
    }
}