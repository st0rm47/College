// Design a NFA that accepts the language L = {w | w contains the substring "ab" and ends with "a"} over the alphabet {0,1}

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
        if (state == 0)
        {
            if (str[i] == 'a')
                state = 1;
            else
                state = 0;
        }
        else if (state == 1)
        {
            if (str[i] == 'b')
                state = 2;
            else
                state = 1;
        }
        else if (state == 2)
        {
            if (str[i] == 'a')
                state = 3;
            else
                state = 2;
        }
        else if (state == 3)
        {
            if (str[i] == 'a')
                state = 3;
            else
                state = 0;
        }
    }
    if (state == 3)
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");
}
