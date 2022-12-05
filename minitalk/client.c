#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void str_to_binary(int pid, char *string)
{
    int j;
    int c_assci;

    while (*string)
    {
        c_assci = *string;
        j = 7;
        while (j + 1 > 0)
        {
            if (c_assci >= (1 << j))
            {
                c_assci = c_assci - (1 << j);
                kill(pid, SIGUSR1);
            }
            else
                kill(pid, SIGUSR2);
            usleep(500);
            j--;
        }
        string++;
    }
}

int main(int c, char *av[])
{
    str_to_binary(atoi(av[1]), av[2]);
    str_to_binary(atoi(av[1]), "\n");
    return (0);
}