// Design a DFA that accepts the substring "aa" over the alphabet {a,b}

#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int state = 0;
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++){
        if (state == 0){
            if (str[i] == 'a')
                state = 1;
            else
                state = 0;
        }else if (state == 1){
            if (str[i] == 'a')
                state = 2;
            else
                state = 0;
        }else if (state == 2){
            state = 2;
        }
        else{
            state = 0;
        }
    }
    if (state == 2)
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");
}