//Question : Given an array of digits, count how many distinct 3-digit even numbers can be formed.
#include <stdio.h>

int totalNumbers(int digits[], int digitsSize) {

    int count = 0;

    // Check all 3-digit even numbers
    for (int num = 100; num <= 998; num += 2) {

        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        int need[10] = {0};

        need[a]++;
        need[b]++;
        need[c]++;

        int possible = 1;

        // Check whether required digits are available
        for (int i = 0; i < 10; i++) {

            int available = 0;

            for (int j = 0; j < digitsSize; j++) {
                if (digits[j] == i)
                    available++;
            }

            if (need[i] > available) {
                possible = 0;
                break;
            }
        }

        if (possible)
            count++;
    }

    return count;
}

int main() {

    int n;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    int digits[n];

    printf("Enter digits: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &digits[i]);
    }

    int result = totalNumbers(digits, n);

    printf("Number of unique 3-digit even numbers = %d\n", result);

    return 0;
}