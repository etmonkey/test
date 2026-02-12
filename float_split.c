#include<stdio.h>

#define PIPE_NUM 8

int main() {
    int float_min, float_max;
    float_min = 0x00800000;
    float_max = 0x7F7FFFFF;
    int float_gap = (float_max-float_min+1) / PIPE_NUM;
    int float_split[PIPE_NUM+1];
    for(int i=0; i<PIPE_NUM; i++) {
        float_split[i] = float_min + float_gap*i;
    }
    float_split[PIPE_NUM] = float_max;
    for(int i=0; i<PIPE_NUM+1; i++) {
        printf("%x ", float_split[i]);
    }
    printf("\n");
    for(int i=1; i<PIPE_NUM+1; i++) {
        printf("%d ", float_split[i] - float_split[i-1]);
    }
    printf("\n");
}
