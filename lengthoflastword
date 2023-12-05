#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count the characters in the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
int main() {
    // Assuming the maximum length of the input is 100 characters
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if present
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("Length of last word is %d\n", lengthOfLastWord(input));

    return 0;
}
