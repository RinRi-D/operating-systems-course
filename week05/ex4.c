#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int n = 0;

// You will be locking and unlocking this
pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;

// Don't modify these variables directly, use the functions below.
int next_number_to_check = 0;
int primes_found_so_far = 0;

int get_number_to_check() {
    int ret = next_number_to_check;
    if (next_number_to_check != n)
        next_number_to_check++;
    return ret;
}

void increment_primes() { primes_found_so_far++; }

void *check_primes(void *arg) {
    /*
      TODO
      Complete this function. This function loops forever, continuously taking a
      value from get_number_to_check and, if it turns out to be prime,
      increments the global prime counter with increment_primes. Once
      get_number_to_check returns <n>, the function exits. Pay close attention
      to your use of the global mutex.
    */
    while(1) {
        pthread_mutex_lock(&global_lock);
        int num = get_number_to_check();
        pthread_mutex_unlock(&global_lock);

        if (is_prime(num)) {
            pthread_mutex_lock(&global_lock);
            increment_primes();
            pthread_mutex_unlock(&global_lock);
        }
        if (num == n)
            return NULL;
    }
}

int main(int argc, char *argv[]) {
    int n_threads = atoi(argv[2]);
    n = atoi(argv[1]);

    pthread_mutex_init(&global_lock, NULL);
    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));
    for (int i = 0; i < n_threads; i++) {
        /*
          TODO
          Spawn <n_threads> threads.
        */
        pthread_create(&threads[i], NULL, &check_primes, NULL);
    }
    for (int i = 0; i < n_threads; i++) {
        /*
          TODO
          Join the threads.
        */
        pthread_join(threads[i], NULL);
    }

    /*
      TODO
      Free the allocated memory.
    */
    pthread_mutex_destroy(&global_lock);

    printf("%d\n", primes_found_so_far);
    exit(EXIT_SUCCESS);
}
