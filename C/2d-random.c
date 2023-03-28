#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//Fill in code below
	//You are fee to write some other functions this function
	//Allocate memory for all the integer (x, y) coordinates inside the boundary
	//Allocate just one memory block
	//Figure out how to map between (x, y) and the index of the array
	//We can treat this allocated memory block as an integer array
	//Write a function for this mapping if needed.

	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as moving up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

	//Do not forget to free the allocated memory block before the function ends.
	
	
	int x = 0, y = 0; // initialize x an y coordinates
	int z = (2 * n - 1); // size of one side on array
	int r, i;
    double steps = 0.0;
    int poss = (z * z) - 1; // number of visited and possible locations
    int *loc = calloc(poss + 1000, sizeof(int)); // allocate memory with all 0s for values
    loc += poss / 2; // initialize pointer to the origin
    loc[poss / 2] = 1.0; // set initial pointer value to 1
    
    while(1){ // condition to break loop
        r = rand() % 4; // random number from 0 to 3
        
        // each of the following conditions iterates either the x or y, moves the pointer, and iterates the value at that pointer
        
        if (r == 0){
            y += 1;
            if (y == n)
                break;
            else{
                for (i = 0; i <= z; i++){
                    loc++;
                }
                ++*loc;
            }
        
        }
        
        if (r == 1){
            x += 1;
            if (x == n)
                break;
            else{
                loc++;
                ++*loc;
            }
        }
        
        if (r == 2){
            y -= 1;
            if (y == -n)
                break;
            else{
                for (i = 0; i <= z; i++){
                    loc--;
                }
                ++*loc;
            }
        }
        
        if (r == 3){
            x -= 1;
            if (x == -n)
                break;
            else{
                loc--;
                ++*loc;
            }
        }
    }
    for (i = 0; i < poss + 1; i++){ // iterates the array and adds 1 to the visited locations if the value is greater then or equal to 1
        if (loc[i] > 0){
            steps += 1.0;
        }
    }  
    // free(loc); // frees the memory
    return steps / (poss + 1); // returns the fraction of visited steps
}

//Do not change the code below
int main()
{
	int trials = 1000;

	srand(12345);
	for(int n=1; n<=256; n*=2)
	{	
		double sum = 0.;
		for(int i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}
