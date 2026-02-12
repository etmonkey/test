#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int main() {
    int a[N];
    for(int i = 0; i < N; i++)
        a[i] = rand() % 100;

    volatile int s;

    for(int i = 0; i < N; i++)
        if(a[i] < 50) s += a[i];
}