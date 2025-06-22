#include <stdio.h>

#define ASCII_LENGTH    128

int main()
{
    long count[ASCII_LENGTH];   // Character counts
    int c;                      // Character buffer

    // Initialise character counts
    for (int i = 0; i < ASCII_LENGTH; i++)
        count[i] = 0;

    // Read and record character input
    while ((c = getchar()) != EOF) {
        count[c]++;
    }

    /* OUTPUT RESULTS */
    // Uppercase letters
    for (int i = 'A'; i <= 'Z'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        printf("\n");
    }
    // Lowercase letters
    for (int i = 'a'; i <= 'z'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        printf("\n");
    }
    // Digits
    for (int i = '0'; i <= '9'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        printf("\n");
    }
    // OTHER CHARACTERS
    // Space
    printf("   | ");
    for (int j = 0; j < count[' ']; j++)
        putchar('#');
    putchar('\n');
    // Newlines
    printf("\\n | ");
    for (int j = 0; j < count['\n']; j++)
        putchar('#');
    printf("\n");
    // Tabs
    printf("\\t | ");
    for (int j = 0; j < count['\t']; j++)
        putchar('#');
    printf("\n");
    // Exclamation to forward slash
    for (int i = '!'; i <= '/'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        putchar('\n');
    }
    // Colons to at symbols
    for (int i = ':'; i <= '@'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        putchar('\n');
    }
    // Left square brackets to backticks
    for (int i = '['; i <= '`'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        putchar('\n');
    }
    // Left curly bracers to tilde
    for (int i = '{'; i <= '~'; i++) {
        printf("%c  | ", i);
        for (int j = 0; j < count[i]; j++)
            putchar('#');
        putchar('\n');
    }

    printf("\n");
}
