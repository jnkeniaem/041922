#include <unistd.h>
#include "ft_printf.h"

//문자열 끝 전까지 이 과정 계속 반복
//이 비트 덩어리를 문자로 바꿔서 문자 출력! < 현희가 말했던게 이 로직(? 아직 로직이 뭔지 모름)인가
//8개 다 차면 한 글자 완료
//받은 비트 8개를 순서대로 배열 앞에서부터 차곡차곡 채우는 시스템
// 문자열 받아서 문자열 출력

handler(int signum) // 8개 비트 넣어주는
{
    int character[8]; // 정수 배열 선언
    int i;
    int j;

    i = 0;
    while (i < )
    j = 0;
    while (j < 8)
    {
        if (signum == SIGUSR1)
        {
            character[j] = 0;
            j++;
            continue;
        }
        if (signum == SIGUSR2)
        {
            character[j] = 1;
            j++;
            continue;
        }
    }
    handler_2(character);

}

handler_2(int *character)
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
    ft_printf("%c", decimal);        

}

//sigaction 으로 신호받을거얌
//sa_sigaction에 핸들러 지정할거얌
struct sigaction s;
sigaction(SIGUSR1, &s, NULL); // sigaction == -1 실패 일때 예외처리
s.sa_flags = SA_SIGINFO;
s.(*sa_sigacion) = handler;

int main(int argc)
{
    int     i;
    char    *s;

    if (argc == 1)//인자 하나일때만 실행되게
    {
        i = getpid(); // server.c의 pid
        ft_printf("server pid : %d\n", getpid());
        
        //두분꺼 코드 봤는데 다 while(1) pause(); main 마지막에 넣으셨네
        return (0);
    }
}
//*sa_handler, sa_mask, sa_restorer 안써도됨.
//결국 struct sigaction에서 가져갈거는 *sa_sigaction, sa_flags 2개
