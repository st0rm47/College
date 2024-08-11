// Design a DFA that accepts the string which has number of 'a' twice than the number of 'b' over the alphabet {a,b}

#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int state = 0;
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') {
            state = (state + 2) % 3;
        } else if (str[i] == 'b') {
            state = (state - 1 + 3) % 3;
        }
    }
    if (state == 0)
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");
}
