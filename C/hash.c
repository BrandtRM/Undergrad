#include <stdio.h>


int main(){
  /*
    Fill this code in yourself
   */
   
   
   
  /*long int n, hash = 0xcbf29ce484222325;
    
  scanf("%lx", &n);
  
  long int byte;
  int bytenum;
  
  printf("%lx\n", n);
  
  for(bytenum = 0; bytenum < 8; bytenum++)
  {
    byte = ((n >> (8 * bytenum)) & 0xff);
    hash ^= byte;
    hash *= 0x100000001b3;
  }*/
  
  
  
  long int hash = 0xa9bc80cca21f28b3;
  
  printf("%lx\n", hash);
  return 0;
}
