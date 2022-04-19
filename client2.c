#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	post(int pid, int b)
{
	if (b == 1) // 나머지가 1이면
		kill(pid, SIGUSR1);
	else // 나머지가 0이면
		kill(pid, SIGUSR2);
	usleep(100);
}

void	conv_and_post(int pid, int c, int num)//pid, 문자열의 문자, 0
{
	if (!c) // 예외처리.
	{
		while (num < 8) // 8번 반복
		{
			post(pid, 0);
			num++;
		}
		return ; // 이게 있어야하나?
	} // server에 0을 보내
	else
	{
		conv_and_post(pid, c / 2, ++num);// 2진수라 '2'로 나눔 
		post(pid, c % 2);
	}
} // num은 바이트 8자리 맞추기 위해 존재하는것같다!

void	post_office(int pid, char *str)//pid랑 문자열
{
	int		c;
	int		num;
	int		last;

	c = 0;
	last = 7;
	while (*str)
	{
		num = 0; // 이건 뭐?
		c = (int)(*str);
		conv_and_post(pid, c, num);
		str++;
	}
	post(pid, 0);// 이
	while (last--) //부분은
		post(pid, 1); //뭐지
	//01111111 : 127
	//아마 문자열의 끝을 나타내기위함이 아닌가
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		write(1, "Client PID : ", 14);
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\n", 1);
		post_office(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}