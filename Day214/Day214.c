//Excel Sheet Column Number
//Question: Convert an Excel column title like A, AB, ZY into its corresponding column number.
#include <stdio.h>

int titleToNumber(char* columnTitle) {
    int result = 0;

    for (int i = 0; columnTitle[i] != '\0'; i++) {
        result = result * 26 + (columnTitle[i] - 'A' + 1);
    }

    return result;
}

int main() {
    char columnTitle[100];

    printf("Enter column title: ");
    scanf("%s", columnTitle);

    printf("Column number: %d\n", titleToNumber(columnTitle));

    return 0;
}