#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int power(int a, int b, int mod) {
    int result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        b = b >> 1;
        a = (a * a) % mod;
    }
    return result;
}

bool isPrime(int n, int k) {
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    while (k > 0) {
        int a = 2 + rand() % (n - 4);
        if (power(a, n - 1, n) != 1)
            return false;
        k--;
    }
    return true;
}

int main() {
    srand(time(0));
    int n = 29;
    int k = 5;

    if (isPrime(n, k))
        printf("%d is prime.\n", n);
    else
        printf("%d is not prime.\n", n);

    return 0;
}

