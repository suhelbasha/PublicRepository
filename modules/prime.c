#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Check if a number is prime
 * @param n: the number to check
 * @return: true if prime, false otherwise
 */
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    // Check for divisors up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

/**
 * Generate and print all prime numbers up to limit
 * @param limit: upper bound for prime generation
 */
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n\nTotal prime numbers found: %d\n", count);
}

/**
 * Generate the first n prime numbers
 * @param n: number of primes to generate
 */
void generate_n_primes(int n) {
    printf("First %d prime numbers:\n", n);
    int count = 0;
    int num = 2;

    while (count < n) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        }
        num++;
    }
    printf("\n\nGenerated %d prime numbers\n", n);
}

int main(int argc, char *argv[]) {
    printf("=== Prime Number Generator ===\n\n");

    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s check <number>        - Check if a number is prime\n", argv[0]);
        printf("  %s generate <limit>      - Generate all primes up to limit\n", argv[0]);
        printf("  %s first <count>         - Generate first N prime numbers\n", argv[0]);
        printf("\nExample:\n");
        printf("  %s check 17\n", argv[0]);
        printf("  %s generate 100\n", argv[0]);
        printf("  %s first 20\n", argv[0]);
        return 1;
    }

    if (argc >= 3) {
        int value = atoi(argv[2]);

        if (strcmp(argv[1], "check") == 0) {
            if (is_prime(value)) {
                printf("%d is a PRIME number\n", value);
            } else {
                printf("%d is NOT a prime number\n", value);
            }
        } else if (strcmp(argv[1], "generate") == 0) {
            if (value > 0) {
                generate_primes(value);
            } else {
                printf("Error: Please provide a positive number\n");
            }
        } else if (strcmp(argv[1], "first") == 0) {
            if (value > 0) {
                generate_n_primes(value);
            } else {
                printf("Error: Please provide a positive number\n");
            }
        } else {
            printf("Error: Unknown command '%s'\n", argv[1]);
            return 1;
        }
    }

    return 0;
}
