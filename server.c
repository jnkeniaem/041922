#include <unistd.h>
#include "ft_printf.h"

//문자열 끝 전까지 이 과정 계속 반복

handler(int signum, siginfo_t *, void *)
{
    int character[8];
    int i;
    int flag;

    i = 0;
    while (1)
    {
	    j = 0;
        while (j < 8)
        {
            if (signum == SIGUSR1)
            {
                character[j] = 0;
                j++;
            }
            if (signum == SIGUSR2)
            {
                character[j] = 1;
                j++;
            }
        }
        flag = handler_2(character);
        if (flag == 0)
            return ;
    }

}

int handler_2(int *character)
{
    int i;
    int decimal;
    int position;

    decimal = 0;
    position = 0;
    i = 0;
    while (i < 8)
    {
        if (character[i] == 1)
            decimal += 1 << position;
        position++;
    }
// 배열 요소 끝 부터 1 위치 시킴
//10 진수로 만들고
    if (decimal == 0)
    //반복을 끊어
	    return 0;//flag
    ft_printf("%c", decimal);
    return 1;

}

int main(int argc)
{
    int     i;
    char    *s;
    struct sigaction s;

    if (argc == 1)
    {
        i = getpid();
        ft_printf("server pid : %d\n", getpid());
        s.sa_flags = SA_SIGINFO;
        s.sa_sigacion = handler;
        sigaction(SIGUSR1, &s, NULL); // sigaction == -1 실패 일때 예외처리
        //두분꺼 코드 봤는데 다 while(1) pause(); main 마지막에 넣으셨네
        return (0);
    }
}