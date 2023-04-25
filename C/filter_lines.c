// TO DO
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {    
	// TO DO

    FILE *fp;
    fp = fopen("input.txt", "r");
    FILE *all;
    all = fopen("output.txt", "w+");
    char buffer[256];
    
    while(fgets(buffer, 256, fp)){
        int cap = 0;
        
        for(int i = 0; i < strlen(buffer); i++){
            if((buffer[i] >= 65 && buffer[i] <= 90)){
                cap = 1;
            }
        }
        
        if(cap != 1){
            fputs(buffer, all);
            //printf("%s\n", buffer);
        }
    }
    
    fclose(fp);
    fclose(all);
    
    return 0;
}