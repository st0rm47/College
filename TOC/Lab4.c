// Design a DFA that accepts the string ending with "bb" over the alphabet {a,b}

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
        if (str[i] == 'a')
            state = 0;
        else if (str[i] == 'b')
            if (state == 0)
                state = 1;
            else if (state == 1 )
                state = 2;
            else if (state == 2)
                state = 2;
            else {
                state = 3;
                break;
            }
    }
    if (state == 2)
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");
    return 0;
}