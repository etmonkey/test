#include<stdio.h>

int my_abs(int x) {
    return (x ^ (x >> 31)) - (x >> 31);
}

int main() {
    for(int i=-1000000; i<1000000; i++){
        printf("%d, %d\n", my_abs(i), my_abs(-i));
    }
}
