#include <stdio.h>


long int recursive_mod(int b, int e, int m)
{
   //Fill in your code below 
    if(e == 1) 
        return b % m;
    else
        return (b % m) * recursive_mod(b, --e, m) % m;
        
}


long int loop_mod(long int b, long int e, long int m)
{
	//Fill in your code below
	int i, res = 1;
    for(i = 1; i <= e; i++)
    {
        res *= b % m;
        res = res % m;
    }
        
    return res;    
    
}
//Do not change the code below
int main(void)
{
    
    int b,e,m;
    
    printf("Enter b:");
    scanf("%d",&b);
    
    printf("Enter e:");
    scanf("%d",&e);
    
    printf("Enter m:");
    scanf("%d",&m);
    
    
    
    printf("Result using loop:%ld\n",loop_mod(b,e,m));
    
    printf("Result using recursion:%ld\n",recursive_mod(b,e,m));
    
    return 0;
}
