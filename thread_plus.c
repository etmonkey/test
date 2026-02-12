#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 10
#define ITERATIONS 10000

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        counter++;                   // 临界区操作
    }
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("最终计数结果: %d\n", counter);
    return 0;
}

