// Design a DFA that accepts the string "aaabbb" over the alphabet {a,b}

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
        if (state == 0 && str[i] == 'a')
            state = 1;
        else if (state == 1 && str[i] == 'a')
            state = 2;
        else if (state == 2 && str[i] == 'a')
            state = 3;
        else if (state == 3 && str[i] == 'b')
            state = 4;
        else if (state == 4 && str[i] == 'b')
            state = 5;
        else if (state == 5 && str[i] == 'b')
            state = 6;
        else
        {
            state = 7;
            break;
        }
    }
    if (state == 6)
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}