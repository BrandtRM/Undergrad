#include <stdio.h>
#include <limits.h>
/*
 * Print the bits in n in four formats:
 *
 * hexadecimal
 * decimal with bits interpreted as signed int
 * decimal with bits interpreted as unsigned int.
 * binary
 */
void print_bits(int n)
{
    // print the integer in different format
    printf("hex:%08X signed:%d unsigned:%u bits:", n, n, n);

    // a loop to print bits from most significant to least significant
    // also an example of sizeof use
    for (int i = sizeof(int) * 8 - 1; i >= 0; i --)
       printf("%d", (n >> i) & 1);
    printf("\n");
}

int main()
{
    int n = INT_MAX, pos;

    print_bits(n);

    // Repeatedly read an integer 'pos' from standard input
    // and clear the bit at position 'pos' if successful.
    // To exit, press Ctrl-D or Ctr-C

    while (scanf("%d", &pos) == 1) {
        // Your code to clear the bit indicated by pos
        // TODO
        n &= ~(1UL << pos);
        // call function to print the bits in n
        print_bits(n);
    };

    /* Let the OS know everything is just peachy. */
    return 0;
}
