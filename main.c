#include <stdio.h>
#include <stdlib.h>

extern int sum_array(int *arr, long n);   // %rdi = arr, %rsi = n, return in %eax

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    long n = 0;
    if (fscanf(fp, "%ld", &n) != 1 || n < 0) {
        fprintf(stderr, "Error: first line must be a non-negative count.\n");
        fclose(fp);
        return 1;
    }

    int *arr = NULL;
    if (n > 0) {
        arr = (int *)malloc((size_t)n * sizeof(int));
    }

    for (long i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: expected %ld integers after the count.\n", n);
            free(arr);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    int sum = sum_array(arr, n);
    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}