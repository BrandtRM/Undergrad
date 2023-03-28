#include <stdio.h>

/*
 * Print the bits in n in four formats:
 *
 * hexadecimal
 * decimal with bits interpreted as signed int.
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
    int n, x, y;

    // Repeatedly read an integer 'n' from standard input and
    // swap left and right double bytes into 'n1' if successful.
    // To exit, press Ctrl-D or Ctr-C
    while (scanf("%d", &n) == 1) {
        int n1 = 0;

        // Your code to swap left and right double bytes in n and 
        // save the changed value in n1.
        // TODO
        x = n >> 16;
        y = n << 16;
        n1 = x | y;
        // call function to print the bits in n and n1
        print_bits(n);
        print_bits(n1);
    };

    /* Let the OS know everything is just peachy. */
    return 0;
}
