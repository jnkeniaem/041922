#include "ft_printf.h"
#include "libft.h"
#include <signal.h>

void send(int pid, int b)
{
    if (b == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
        usleep(100);//임의로 100 넣겠음
}

void binary_num(int pid, int c, int fill)
{
    if (c == 0)
    {
        while (fill < 8)
        {
            send(pid, 0);
            fill++;
        }
    }
    else
    {
        binary_num(pid, c / 2, ++fill);
        send(pid, c % 2);
    }
}

void single_char(int pid, char *s)
{
    int i;
    int fill;

    i = 0;
    while (*s)
    {
        fill = 0;
        binary_num(pid, (int)*s, fill);
        s++;
    }
    while (i < 8)
    {
        send(pid, 0);
        i++;
    }
}

int main(int argc,  char **argv)
{
    if (argc == 3 && ft_atoi(argv[1]) > 100 && ft_atoi(argv[1]) < 99999)
    {
        ft_printf("client pid : %d", getpid()); // 개행 안들어가도 될것같아
        single_char(ft_atoi(argv[1]), argv[2]);    
    }
    return (0);
}