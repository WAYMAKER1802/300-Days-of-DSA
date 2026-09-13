//Question : Given an integer num, convert it into its Roman numeral representation.
#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {

    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    char* symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    char* result = (char*)malloc(20 * sizeof(char));

    int pos = 0;

    for (int i = 0; i < 13; i++) {

        while (num >= values[i]) {

            char* s = symbols[i];

            while (*s != '\0') {
                result[pos++] = *s;
                s++;
            }

            num -= values[i];
        }
    }

    result[pos] = '\0';

    return result;
}

int main() {

    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    char* result = intToRoman(num);

    printf("Roman numeral: %s\n", result);

    free(result);

    return 0;
}