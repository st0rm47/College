// Design a DFA that contains odd number of 1's over the alphabet {0,1}

#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int state = 0; 
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            continue;
        } else if (str[i] == '1') {
            state = 1 - state;
        }
    }
    if (state == 1)
        printf("String is accepted.\n");  
    else
        printf("String is rejected.\n");
}
