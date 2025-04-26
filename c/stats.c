#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

double mean(int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return (double)sum / n;
}

double median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare_ints);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

void mode(int arr[], int n, int **modes, int *mode_count, int *freq) {
    qsort(arr, n, sizeof(int), compare_ints);
    int max_count = 1, curr_count = 1;
    *mode_count = 0;
    *modes = malloc(n * sizeof(int));

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            curr_count++;
        } else {
            if (curr_count > max_count) {
                max_count = curr_count;
                *mode_count = 0;
                (*modes)[(*mode_count)++] = arr[i-1];
            } else if (curr_count == max_count) {
                (*modes)[(*mode_count)++] = arr[i-1];
            }
            curr_count = 1;
        }
    }
    // last run
    if (curr_count > max_count) {
        max_count = curr_count;
        *mode_count = 0;
        (*modes)[(*mode_count)++] = arr[n-1];
    } else if (curr_count == max_count) {
        (*modes)[(*mode_count)++] = arr[n-1];
    }
    *freq = max_count;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *arr = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    double m = mean(arr, n);
    double med = median(arr, n);

    int *modes;
    int mode_count, freq;
    mode(arr, n, &modes, &mode_count, &freq);

    printf("Mean: %.2f\n", m);
    printf("Median: %.2f\n", med);
    printf("Mode (%d occurrences): ", freq);
    for (int i = 0; i < mode_count; i++) {
        printf("%d ", modes[i]);
    }
    printf("\n");

    free(arr);
    free(modes);
    return 0;
}
