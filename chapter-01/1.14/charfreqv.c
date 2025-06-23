#include <stdio.h>

#define ASCII_LENGTH    128

int main()
{
    long count[ASCII_LENGTH];   // Character counts
    int c;                      // Character buffer
    int highest_count = 0;

    // Initialise character counts
    for (int i = 0; i < ASCII_LENGTH; i++)
        count[i] = 0;

    // Read and record character input
    while ((c = getchar()) != EOF) {
        count[c]++;
        if (count[c] > highest_count)
            highest_count = count[c];
    }

    /* OUTPUT RESULTS */
    printf("\n");

    for (int row = highest_count; row > 0; row--) {
        // Uppercase letters
        for (int col = 'A'; col <= 'Z'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }
        // Uppercase letters
        for (int col = 'a'; col <= 'z'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }
        // Digits
        for (int col = '0'; col <= '9'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }
        // OTHER CHARACTERS
        // Space
        if (count[' '] >= row)
            printf("# ");
        else
            printf("  ");
        // Newlines
        if (count['\n'] >= row)
            printf("# ");
        else
            printf("  ");
        // Tabs
        if (count['\t'] >= row)
            printf("# ");
        else
            printf("  ");
        // Exclamation to forward slash
        for (int col = '!'; col <= '/'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }
        // Colons to at symbols
        for (int col = ':'; col <= '@'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }
        // Left square brackets to backticks
        for (int col = '['; col <= '`'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }
        // Left curly bracers to tilde
        for (int col = '{'; col <= '~'; col++) {
            if (count[col] >= row)
                printf("# ");
            else
                printf("  ");
        }

        putchar('\n');
    }

    /* OUTPUT HYPHEN BREAK */
    // Uppercase letters
    for (int col = 'A'; col <= 'Z'; col++)
        printf("--");
    // Uppercase letters
    for (int col = 'a'; col <= 'z'; col++)
        printf("--");
    // Digits
    for (int col = '0'; col <= '9'; col++)
        printf("--");
    // OTHER CHARACTERS
    // Space, newlines, and tab
    printf("------");
    // Exclamation to forward slash
    for (int col = '!'; col <= '/'; col++)
        printf("--");
    // Colons to at symbols
    for (int col = ':'; col <= '@'; col++)
        printf("--");
    // Left square brackets to backticks
    for (int col = '['; col <= '`'; col++)
        printf("--");
    // Left curly bracers to tilde
    for (int col = '{'; col <= '~'; col++)
        printf("--");
    putchar('\n');

    /*
        Output key
    */
    // Uppercase letters
    for (int col = 'A'; col <= 'Z'; col++)
        printf("%c ", col);
    // Uppercase letters
    for (int col = 'a'; col <= 'z'; col++)
        printf("%c ", col);
    // Digits
    for (int col = '0'; col <= '9'; col++)
        printf("%c ", col);
    // OTHER CHARACTERS
    // Space
    printf("  ");
    // Newlines
    printf("\\n");
    // Tabs
    printf("\\t");
    // Exclamation to forward slash
    for (int col = '!'; col <= '/'; col++)
        printf("%c ", col);
    // Colons to at symbols
    for (int col = ':'; col <= '@'; col++)
        printf("%c ", col);
    // Left square brackets to backticks
    for (int col = '['; col <= '`'; col++)
        printf("%c ", col);
    // Left curly bracers to tilde
    for (int col = '{'; col <= '~'; col++)
        printf("%c ", col);

    putchar('\n');

    printf("\n");
}
