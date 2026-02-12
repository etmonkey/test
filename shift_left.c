#include <stdio.h>

int main()
{
    unsigned int i = 0xffffffff;
    printf("sizeof ui is %ld\n", sizeof(i));
    printf("ui shift left 16: %u\n", i<<16);
    printf("ui shift left 80: %u\n", i<<80);
}