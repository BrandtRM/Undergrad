#include <stdio.h>
#include <stdlib.h>

int direction()
{
	//Generate a random number to determine the direciton of the next step
	if(rand()%2 == 0) return -1;
	else return 1;
}

//Implement the following function
//The random walker starts from 0.
//At every step, the walker can go to clockwise direction if the direction() functions returns 1
//or go to counter-clockwise direciton if the direction() function returns -1
//The function returns after the walker returns to 0.
//The return value of the function is the number of steps taken until the walker returns to 0
int circular_random_walk(int k)
{
	//Fill in your code below
    int num = 0, cur= 0;
    
    do{
        int dir = direction();
        cur += dir;
        num += 1;
        
        if(cur < 0){
            cur = k - 1;
        }
        else
            if(cur >= k){
                cur = 0;
            }
    }

    while(cur != 0);
    return num;
}
	
//Do not change the following code.
int main()
{
	int i;
	double sum;
	int steps;
	//Set the seed of the random number generator to 12345
	srand(12345);
	int k;
	printf("Enter k: ");
	scanf("%d", &k);
	sum = 0.;
	int n = 1000000;
	int max = 0;
	for(i=1; i<= n; i++)
		{
			steps = circular_random_walk(k);
			sum += steps;
			if(steps > max) max = steps;
		}
	printf("average=%.3lf, max = %d \n", sum/n, max);
	return 0;
}
