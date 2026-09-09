//Question - Given n, count the total number of commas used when writing every number from 1 to n in standard format.
//1–999 → 0 commas
//1,000–999,999 → 1 comma
//1,000,000–999,999,999 → 2 commas and so on.
#include <stdio.h>

long long countCommas(long long n) {
    long long ans = 0;
    long long x = 1000;

    while (x <= n) {
        ans += n - x + 1;
        x *= 1000;
    }

    return ans;
}

int main() {
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Total commas = %lld\n", countCommas(n));

    return 0;
}