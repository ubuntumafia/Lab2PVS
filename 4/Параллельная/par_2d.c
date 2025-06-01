#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int main() {
    const char *env_size = getenv("ARRAY_SIZE");
    int size = env_size ? atoi(env_size) : 500;
    
    // Выделение памяти
    double **a = (double**)malloc(size * sizeof(double*));
    double **b = (double**)malloc(size * sizeof(double*));
    double **sum = (double**)malloc(size * sizeof(double*));
    double **sub = (double**)malloc(size * sizeof(double*));
    double **mul = (double**)malloc(size * sizeof(double*));
    double **div = (double**)malloc(size * sizeof(double*));
    
    for (int i = 0; i < size; i++) {
        a[i] = (double*)malloc(size * sizeof(double));
        b[i] = (double*)malloc(size * sizeof(double));
        sum[i] = (double*)malloc(size * sizeof(double));
        sub[i] = (double*)malloc(size * sizeof(double));
        mul[i] = (double*)malloc(size * sizeof(double));
        div[i] = (double*)malloc(size * sizeof(double));
    }

    // Инициализация
    srand(time(NULL));
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = rand() / (double)RAND_MAX * 100.0;
            b[i][j] = rand() / (double)RAND_MAX * 100.0 + 0.1;
        }
    }

    double start = omp_get_wtime();

    // Параллельные вычисления
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            sub[i][j] = a[i][j] - b[i][j];
            mul[i][j] = a[i][j] * b[i][j];
            div[i][j] = a[i][j] / b[i][j];
        }
    }

    double time = omp_get_wtime() - start;
    printf("Parallel 2D: Size %dx%d. Threads: %d. Time: %.6f sec\n", 
           size, size, omp_get_max_threads(), time);

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        free(a[i]); free(b[i]); free(sum[i]); free(sub[i]); free(mul[i]); free(div[i]);
    }
    free(a); free(b); free(sum); free(sub); free(mul); free(div);
    
    return 0;
}