#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *env_size = getenv("ARRAY_SIZE");
    int N = env_size ? atoi(env_size) : 250000;

    double *a = malloc(N * sizeof(double));
    double *b = malloc(N * sizeof(double));
    double *sum = malloc(N * sizeof(double));
    double *sub = malloc(N * sizeof(double));
    double *mul = malloc(N * sizeof(double));
    double *div = malloc(N * sizeof(double));

    srand(42);
    for (int i = 0; i < N; i++) {
        a[i] = rand() / (double)RAND_MAX * 100.0;
        b[i] = rand() / (double)RAND_MAX * 100.0;
    }

    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        sum[i] = a[i] + b[i];
        sub[i] = a[i] - b[i];
        mul[i] = a[i] * b[i];
        div[i] = a[i] / (b[i] + 1e-10);  // Защита от деления на 0
    }

    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Sequential N=%d. Time: %.6f sec\n", N, time);

    free(a); free(b); free(sum); free(sub); free(mul); free(div);
    return 0;
}
