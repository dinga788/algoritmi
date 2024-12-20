#include <stdio.h>
#define MAX_DIGITS 256

typedef struct {
    int digits[MAX_DIGITS];
    int numDigits;
} BigNum;

void init(BigNum* num) {
    num->digits[0] = 1;
    num->numDigits = 1;
}

void multiply(BigNum* num, int factor) {
    int carry = 0;
    for (int i = 0; i < num->numDigits; ++i) {
        int product = num->digits[i] * factor + carry;
        num->digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        num->digits[num->numDigits++] = carry % 10;
        carry /= 10;
    }
}

void printBigNum(const BigNum* num) {
    for (int i = num->numDigits - 1; i >= 0; --i) {
        printf("%d", num->digits[i]);
    }
}

int main() {
    BigNum factorial;
    init(&factorial);

    for (int i = 2; i <= 100; ++i) {
        multiply(&factorial, i);
    }

    printf("\nFactorial cisla 100: ");
    printBigNum(&factorial);

    printf("\nColicestvo cifr v factoriale cisla 100: %d\n", factorial.numDigits);

    return 0;
}