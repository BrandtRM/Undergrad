#include <stdio.h>
#include <float.h>

int main() {
    int n;
    scanf("%d", &n);
    
    float f;
    float min, max;
    
    //TODO
    
    min = FLT_MAX;
    max = -FLT_MAX;
    
    for (int i=0; i<n; i++) {
        scanf("%f", &f);
        
        if(i == 0)
        {
            min = f;
            max = f;
        }
        
        if(f > max)
        {
            max = f;
        }
        
        if(f < min)
        {
            min = f;
        }
        //TODO
    }

    // DO NOT EDIT BELOW THIS LINE
    printf("The minimum value is: %.05f.\n", min);
    printf("The maximum value is: %.05f.\n", max); 
    
    /* Let the OS know everything is just peachy. */
    return 0;
}