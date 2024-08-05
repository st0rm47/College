// Design a DFA that accepts the string "0010" over the alphabet {0,1}

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int state = 0;
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (state == 0 && str[i] == '0')
            state = 1;
        else if (state == 1 && str[i] == '0')
            state = 2;
        else if (state == 2 && str[i] == '1')
            state = 3;
        else if (state == 3 && str[i] == '0')
            state = 4;
        else
        {
            state = 5;
            break;
        }
    }
    if (state == 4)
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}