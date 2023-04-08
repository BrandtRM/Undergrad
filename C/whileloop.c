#include    <stdio.h>

int main()
{
    int i;
    int odd, even;

    // count the number of odd numbers and even numbers from 0 to 199
    i=0;
    while (i < 200){
         if (i & 1) {
            odd++;
        }
        else {
            even++;
        }
    ++i;
    }
    printf("odd=%d even=%d\n", odd, even);
    return 0;
}

