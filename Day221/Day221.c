//Given two integers dividend and divisor, divide them without using multiplication (*), division (/), or modulo (%) operators.
//The quotient must be truncated toward zero. If it overflows a 32-bit signed integer, return INT_MAX or INT_MIN as required.

#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = dividend;
    long long b = divisor;

    int negative = (a < 0) != (b < 0);

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long result = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        result += multiple;
    }

    if (negative)
        result = -result;

    return (int)result;
}

int main() {
    int dividend, divisor;

    printf("Enter dividend and divisor: ");
    scanf("%d %d", &dividend, &divisor);

    if (divisor == 0) {
        printf("Division by zero is undefined.\n");
        return 0;
    }

    printf("Quotient = %d\n", divide(dividend, divisor));

    return 0;
}
