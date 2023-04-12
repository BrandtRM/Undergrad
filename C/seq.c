#include <stdio.h>
#include <assert.h>

/* This function calculates the balance after n-th month.
 * n is assumed to be non-negative. i is the annual interest rate in percent.
 * For example, i = 5 means the anual interest rate if 5%.
 * Do not worry about overflow.
 * Do not print anything in this function.
 */
float balance(int n, int i)
{
    assert(n>=0);

    // TODO
    // base step
    if(n == 0) return 1000;

    // recursion
    return balance(--n, i) * 1.00416666;
 
}

/* do not change the main function */
int main()
{
    int n,i;
    printf("Enter n:");
    scanf("%d",&n);
    
    printf("Enter i:");
    scanf("%d",&i);
    
    
    printf("After %d months, $1,000 becomes $%.2f\n", n, balance(n,i));
    return 0;
}
