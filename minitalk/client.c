#include "ft_printf.h"
#include "libft.h"

void send(int pid, int b)
{
    if (b == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
        //신호 보내는 갭이 신호 받는 갭보다 짧아서 usleep 써줘야하는데 얼마만큼 설정해줘야할지...
        usleep();
}

void binary_num(int pid, int c, int fill) // 받은 문자를 2진수로 쪼개
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
// 인수로 "\0abc"를 받으면 abc는 무시되는 식~ 
void single_char(int pid, char *s)
{
    int i;
    int fill;

    i = 0;
    while (*s) // 인수로 받은 문자열 돌면서
    {
        fill = 0;
        binary_num(pid, (int)*s, fill);
        s++;
    }
    while (i < 8)
    {
        send(pid, 0);
        i++;
    }// 문자열의 비트 다 보내면 문자열 끝났다고 알려줘야해.
}

int main(int argc,  char **argv)
{
    if (argc == 3 && ft_atoi(argv[1]) > 100 && ft_atoi(argv[1]) < 99999)
    {
        ft_printf("client pid : %d\n", getpid());//개행 들어가야하나?
        //문자열을 앞에서부터 문자하나하나 2진수로 표현해서 0이면 sigusr1 1이면 sigusr2 이런식으로 매칭해서 서버로 보내
        single_char(argv[1], argv[2]);    
    }
    return (0);
}