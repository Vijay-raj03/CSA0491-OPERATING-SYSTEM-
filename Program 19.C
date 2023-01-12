#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;
int shared_resource = 0;

void *increment_resource(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);
        shared_resource++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, increment_resource, NULL);
    pthread_create(&thread2, NULL, increment_resource, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared resource: %d\n", shared_resource);
    pthread_mutex_destroy(&lock);
    return 0;
}
