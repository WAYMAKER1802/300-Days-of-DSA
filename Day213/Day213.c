//Reverse Substrings Between Each Pair of Parentheses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseParentheses(char* s) {
    int n = strlen(s);

    // Store matching parentheses
    int* pair = malloc(n * sizeof(int));
    int* stack = malloc(n * sizeof(int));

    int top = -1;

    // Find matching brackets
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        }
        else if (s[i] == ')') {
            int open = stack[top--];

            pair[open] = i;
            pair[i] = open;
        }
    }

    char* result = malloc((n + 1) * sizeof(char));

    int pos = 0;
    int i = 0;
    int direction = 1;

    while (i >= 0 && i < n) {

        if (s[i] == '(' || s[i] == ')') {
            // Jump to matching bracket
            i = pair[i];

            // Change direction
            direction = -direction;
        }
        else {
            result[pos++] = s[i];
        }

        i += direction;
    }

    result[pos] = '\0';

    free(pair);
    free(stack);

    return result;
}

int main() {

    char s[1000];

    printf("Enter string: ");
    scanf("%999s", s);

    char* result = reverseParentheses(s);

    printf("Output: %s\n", result);

    free(result);

    return 0;
}