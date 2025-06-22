#include <stdio.h>

#define ALPHABET_LENGTH     26  // Length of the alphabet
#define NUMBER_OF_DIGITS    10  // Number of unique digits

int main()
{
    long uppercase[ALPHABET_LENGTH];     // Occurrences of uppercase letters
    long lowercase[ALPHABET_LENGTH];     // Occurrences of lowercase letters
    long digits[NUMBER_OF_DIGITS];       // Occurrences of each digit
    long space_count = 0;                // Occurrences of spaces
    long period_count = 0;               // Occurrences of periods
    long comma_count = 0;                // Occurrences of commas
    long exclamation_count = 0;          // Occurrences of exclamation marks
    long question_count = 0;             // Occurrences of question marks
    long newline_count = 0;              // Occurrences of newlines
    long single_quote_count = 0;        // Occurrences of single quotes
    long double_quote_count = 0;        // Occurrences of double quotes
    long hyphen_count = 0;               // Occurrences of hyphens
    long colon_count = 0;                // Occurrences of colons
    long semicolon_count = 0;            // Occurrences of semicolons
    long ampersand_count = 0;            // Occurrences of ampersands
    int c;                               // Character buffer

    // Initialize arrays
    for (int i = 0; i < ALPHABET_LENGTH; i++)
        uppercase[i] = 0;
    for (int i = 0; i < ALPHABET_LENGTH; i++)
        lowercase[i] = 0;
    for (int i = 0; i < NUMBER_OF_DIGITS; i++)
        digits[i] = 0;

    // Count characters
    while((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            uppercase[c - 'A']++;
        else if (c >= 'a' && c <= 'z')
            lowercase[c - 'a']++;
        else if (c >= '0' && c <= '9')
            digits[c - '0']++;
        else if (c == ' ')
            space_count++;
        else if (c == '.')
            period_count++;
        else if (c == ',')
            comma_count++;
        else if (c == '!')
            exclamation_count++;
        else if (c == '?')
            question_count++;
        else if (c == '\n')
            newline_count++;
        else if (c == '\'')
            single_quote_count++;
        else if (c == '\"')
            double_quote_count++;
        else if (c == ':')
            hyphen_count++;
        else if (c == ';')
            semicolon_count++;
        else if (c == '&')
            ampersand_count++;
    }

    // Print histogram
    // Uppercase characters
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        printf("%c | ", i + 'A');
        for (long j = 0; j < uppercase[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    // Lowercase characters
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        printf("%c | ", i + 'a');
        for (long j = 0; j < lowercase[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    // Digits
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        printf("%c | ", i + '0');
        for (long j = 0; j < digits[i]; j++)
            putchar('#');
        putchar('\n');
    }
    // Spaces
    printf("  | ");
    for (long i = 0; i < space_count; i++)
        putchar('#');
    putchar('\n');
    // Periods
    printf(". | ");
    for (long i = 0; i < period_count; i++)
        putchar('#');
    putchar('\n');
    // Commas
    printf(", | ");
    for (long i = 0; i < comma_count; i++)
        putchar('#');
    putchar('\n');
    // Exclamation marks
    printf("! | ");
    for (long i = 0; i < exclamation_count; i++)
        putchar('#');
    putchar('\n');
    // Question marks
    printf("? | ");
    for (long i = 0; i < question_count; i++)
        putchar('#');
    putchar('\n');
    // Newlines
    printf("\\n| ");
    for (long i = 0; i < newline_count; i++)
        putchar('#');
    putchar('\n');
    // Single quotes
    printf("\' | ");
    for (long i = 0; i < single_quote_count; i++)
        putchar('#');
    putchar('\n');
    // Double quotes
    printf("\" | ");
    for (long i = 0; i < double_quote_count; i++)
        putchar('#');
    putchar('\n');
    // Hyphens
    printf("- | ");
    for (long i = 0; i < hyphen_count; i++)
        putchar('#');
    putchar('\n');
    // Double quotes
    printf("\" | ");
    for (long i = 0; i < double_quote_count; i++)
        putchar('#');
    putchar('\n');
    // Colons
    printf(": | ");
    for (long i = 0; i < colon_count; i++)
        putchar('#');
    putchar('\n');
    // Semicolons
    printf("; | ");
    for (long i = 0; i < semicolon_count; i++)
        putchar('#');
    putchar('\n');
    // Ampersands
    printf("& | ");
    for (long i = 0; i < ampersand_count; i++)
        putchar('#');
    putchar('\n');
}
