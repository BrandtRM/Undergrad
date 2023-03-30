#include <stdio.h>


int fibonacci(int n)
{
    
    if(n==0) return 0;
    if(n==1) return 1;
    
    return fibonacci(--n)+fibonacci(--n);
    
}


int main(void)
{
    
    int n;
    printf("Enter a number between 1 and 10:");
    scanf("%d",&n);
    printf("Fibonacci(n)=%d\n",fibonacci(n));
    
    
}
