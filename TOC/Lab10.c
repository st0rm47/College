// Constructing a PDA that accepting the language L = {a^nb^n | n>= 0}

#include <stdio.h>
#include <string.h>

int main(){
    int state = 0;
    int top = 0;
    char stack[100];
    stack[top] = 'Z';

    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++){
        if (state == 0){
            if (str[i] == 'a'){
                stack[++top] = 'a';
                state = 1;
            }else{
                state = 0;
            }
        }else if (state == 1){
            if (str[i] == 'a'){
                stack[++top] = 'a';
                state = 1;
            }else if (str[i] == 'b'){
                if (stack[top] == 'a'){
                    top--;
                    state = 2;
                }else{
                    state = 0;
                }
            }else{
                state = 0;
            }
        }else if (state == 2){
            if (str[i] == 'b'){
                if (stack[top] == 'a'){
                    top--;
                    state = 2;
                }else{
                    state = 0;
                }
            }else{
                state = 0;
            }
        }else{
            state = 0;
        }
    }
    if (state == 2 && top == 0)
        printf("String is accepted.\n");
    else
        printf("String is rejected.\n");

    return 0;

}