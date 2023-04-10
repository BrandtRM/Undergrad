#include <stdio.h>
#include <stdlib.h>

//You might need the below function
//This function returns the length of a string
//It is equivlent to strlen() in string.h

int lenstr(char* s) {
	int len = 0;
	while(s[len++] != '\0');
	return len-1;
}

/** Appends the src string to the end of the
 *  dest string. Return the resulting string. */

char* strcat(char dest[], char src[]) {
    
	//Add your code here
	
    int i, j = 0;
    int len1 = lenstr(dest);
    int len2 = lenstr(src);
    char *res = (char*)malloc(len1 + len2 + 1);
    
    for (i = 0; i < len1; i++){
        res[j++] = dest[i];
    }
    for (i = 0; i < len2; i++){
        res[j++] = src[i];
    }
    return res;
}


/** Searches the haystack string for the needle 
 *  substring. Return a pointer to the located 
 *  needle substring in the haystack string if 
 *  it exists (and the first if there are more 
 *  than one), or NULL if the needle is not in 
 *  the haystack. */

char* strstr(char haystack[], char needle[]){

	//Add your code here
    int i; 
    for(i = 0; i < lenstr(haystack); i++){
      char *p = needle;
      char *q = haystack;
      while ( *p != '\0' && *q != '\0' && *p == *q){ 
         p++;
         q++;
      }
      if( *p == '\0' ) 
         return haystack;
   }  
   return NULL;
}




/** Searches for the first occurrence of the 
 *  character c in the string s and returns a
 *  pointer to it. If c does not appear in s,
 *  return NULL. */

char* str_chr(char s[], char c) {

	//Add your code here

    int i;
    for (i = 0; i < lenstr(s); i++){
        if (c == s[i]){
            return &s[i];
        }
    }
    return NULL;
}

/** Returns a pointer to a new string which is
 *  a copy of the given string s. */

char* strdup(char s[]) {
	//Add your code here
    
    int i;
    int len1 = lenstr(s);
    char *res = (char*)malloc(len1 + 1);
    
    for (i = 0; i < len1; i++){
        res[i] = s[i];
    }
    return res;
}


/** Returns 1 if the strings s1 and s2 are the
 *  same, returns 0 otherwise. */

int streq(char s1[], char s2[]) {
	//Add your code here

    int i;
    int len1 = lenstr(s1);
    int len2 = lenstr(s2);
    
    if (len1 != len2)
        return 0;
    else{
        for (i = 0; i < len1; i++){
            if (s1[i] == s2[i])  
                continue;
            else
                return 0;
        }
    }
    return 1;
}


/** Main function. Add code to free allocated memory! 
 *  Valgrind should NOT yield any errors once you're done!
 *  DO NOT CHANGE OUTPUTS! JUST ADD CLEAN UP CODE!  */
int main(int argc, char** argv) {
	
	/* Read strings from program arguments */
	if(argc != 3) {
		printf("usage: ./strfuncs s1 s2\n");
		return 1;
	}
	char* s1 = argv[1];
	char* s2 = argv[2];
	printf("String 1: %s\n", s1);
	printf("String 2: %s\n\n", s2);
	
	/* Check for string equality */
	int s1eqs2 = streq(s1, s2);
	printf("s1=s2? %s\n\n", s1eqs2 ? "yes" : "no");
	
	/* Concatenate s1 to s2 and s2 to s1 */
	char* s1s2 = strcat(s1, s2);
	char* s2s1 = strcat(s2, s1);
	printf("s1+s2=%s\n", s1s2);
	printf("s2+s1=%s\n\n", s2s1);
	
	/* Check for substrings */
	char* s1ins2 = strstr(s2, s1);
	char* s2ins1 = strstr(s1, s2);
	printf("s1 in s2 -> %s\n", s1ins2 == NULL ? "no" : "yes");
	printf("s2 in s1 -> %s\n\n", s2ins1 == NULL ? "no" : "yes");
	
	/* Check for character occurence */
	char* ains1 = str_chr(s1, 'a');
	printf("'a' in s1? %s\n\n", ains1 == NULL ? "no" : "yes");
	
	/* Check duplication of strings */
	char* dups1 = strdup(s1);
	printf("dup(s1)=%s\n", dups1);
	
	/* Clean up, i.e. free memory! */
	//Add your code here
	free(dups1);
	free(s1s2);
	free(s2s1);
	/* Done! */
	return 0;
}

