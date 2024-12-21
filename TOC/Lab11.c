// Construct a TM to accept the language L = {a^nb^nc^n | n>= 0}

#include <stdio.h>
#include <string.h>

int isValidLanguage(char *str) {
    int length = strlen(str);

    // Check if the length is divisible by 3
    if (length % 3 != 0) {
        return 0;  // Reject if not divisible by 3
    }

    int i = 0;
    // Mark 'a's with 'X'
    while (str[i] == 'a') {
        str[i] = 'X';  // Mark 'a'
        i++;
    }

    // Look for 'b's and mark with 'Y'
    while (str[i] == 'b') {
        str[i] = 'Y';  // Mark 'b'
        i++;
    }

    // Look for 'c's and mark with 'Z'
    while (str[i] == 'c') {
        str[i] = 'Z';  // Mark 'c'
        i++;
    }

    // Check if all characters are marked
    for (int j = 0; j < length; j++) {
        if (str[j] == 'a' || str[j] == 'b' || str[j] == 'c') {
            return 0;  // Reject if any character is unmarked
        }
    }

    return 1;  // Accept if all characters are marked
}

int main() {
    char input[100];

    // Get the input string
    printf("Enter the string: ");
    scanf("%s", input);

    // Check if the string belongs to the language a^n b^n c^n
    if (isValidLanguage(input)) {
        printf("String is accepted.\n");
    } else {
        printf("String is rejected.\n");
    }

    return 0;
}
