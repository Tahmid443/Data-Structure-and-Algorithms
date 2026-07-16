#include <stdio.h>

int main() {
    double n, low, high, mid;
    double diff = 0.000001;   // Accuracy up to 6 decimal places

    printf("Enter a positive number: ");
    scanf("%lf", &n);

    if (n < 0) {
        printf("Square root of a negative number is not a real number.\n");
        return 0;
    }

    if (n == 0 || n == 1) {
        printf("Square root = %.6lf\n", n);
        return 0;
    }

    if (n < 1) {
        low = 0;
        high = 1;
    } else {
        low = 0;
        high = n;
    }

    while ((high - low) > diff) {
        mid = (low + high) / 2;

        if (mid * mid < n)
            low = mid;
        else
            high = mid;
    }

    printf("Square root = %.2lf\n", (low + high) / 2);

    return 0;
}