#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

typedef struct {
    pthread_t id;
    int i;
    char mes[256];
} Thread;

void *print_thread(void *argv) {
    Thread *t = argv;
    printf("%d %s\n", t->i, t->mes);
    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char **argv){
    if (argc != 2) {
        printf("Usage: %s [n]\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);

    Thread threads[n];
    for (int i = 0; i < n; ++i) {
        threads[i].i = i;
        snprintf(threads[i].mes, 256, "Hello from thread %d", i);
        printf("Thread %d is created\n", i);
        pthread_create(&threads[i].id, NULL, &print_thread, &threads[i]);
        pthread_join(threads[i].id, NULL);
    }
}
