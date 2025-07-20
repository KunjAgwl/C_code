#include <stdio.h>

// Global pointer
int *mix;

void Runner() {
    int set[] = { 1, 3, 5, 7, 9, 11 };
    // Assign the array's starting address to the global pointer
    mix = set;

    // Use the pointer 'mix' for arithmetic, not the array name 'set'
    printf("%d-", *(mix++)); // Prints the value (1), then increments the pointer
    printf("%d-", *(++mix)); // Increments the pointer, then prints the value (5)
}

int Compute(int z) {
    int val = 0;
    for (int j = 0; j <= 8; j++) {
        if ((z >> j) & 1) {
            // Note: The variable 'k' is assigned but never used.
            int k = z << 1;
            val += j;
        }
    }
    return val;
}

// 'main' should return an integer
int main() {
    static int v = 4;
    while (v < 50) {
        for (int i = 0; i < 8; i++) {
            char out = Compute(i);
            // Use "%d" to print the integer value, not the character
            printf("%d", out);
        }
        Runner();
        v = v + 9;
    }
    // This statement was moved inside the main function
    printf("Done");

    // Return 0 to indicate successful execution
    return 0;
}
