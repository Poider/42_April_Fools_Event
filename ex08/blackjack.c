#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *arr = "23456789TJDKA";

int found(char c)
{
    for(int i = 0 ; i < strlen(arr) ; i++)
    {
        if (c == arr[i])
        return 1;
    }
    return 0;
}
int main(int argc, char **argv)
{
    int A = 0;
    int sum = 0;


    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(!found(argv[1][i]))
        {
            printf("Character not known\n");
            return 1;
        }
        if(isdigit(argv[1][i]))
            sum += argv[1][i] - '0';
        else if(argv[1][i] == 'A')
            A++;
        else
            sum += 10;
    }
    
    for(int i = 0;i < A; i++)
    {
        if(sum <= 21)
        {
            sum += 11;
            if(sum > 21)
                sum-=10;
        }
        else
        {
            sum += 1;
        }
    }
    if(sum == 21)
        printf("Blackjack!\n");
    else
        printf("%d\n",sum);


}