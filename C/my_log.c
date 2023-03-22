#include <stdio.h>
#include <math.h>



int main() {
    float x;
    int n,i;
    double sum = 0.0;    
    
/* Read a number from standard input. Execute the loop if it is successful. */
    /* To exit, press Ctrl-D or Ctr-C */
    while(scanf("%f %d", &x, &n) == 2)
    {
        //Implement your code here
        for(i = 1; i <= n; i++)
        {
            sum += (pow(-1, (i + 1)) * ((pow(x, i)) / i)); 
            
        }
        printf("Sum: %.5f\n", sum);
        sum = 0.0;
    }
    
    /* Let the OS know everything is just peachy. */
    return 0;
}