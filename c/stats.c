#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare_ints(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y); // Returns positive if x > y, negative if x < y, and 0 if equal
}

// Function to calculate the mean of an array
double mean(int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i]; // Sum all elements
    return (double)sum / n; // Return the average
}

// Function to calculate the median of an array
double median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare_ints); // Sort the array
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0; // Average of two middle elements if even
    else
        return arr[n/2]; // Middle element if odd
}

// Function to find the mode(s) of an array
void mode(int arr[], int n, int **modes, int *mode_count, int *freq) {
    qsort(arr, n, sizeof(int), compare_ints); // Sort the array
    int max_count = 1, curr_count = 1;
    *mode_count = 0;
    *modes = malloc(n * sizeof(int)); // Allocate memory for modes

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            curr_count++; // Increment count if same as previous
        } else {
            if (curr_count > max_count) {
                max_count = curr_count; // New max frequency found
                *mode_count = 0; // Reset mode count
                (*modes)[(*mode_count)++] = arr[i-1]; // Add new mode
            } else if (curr_count == max_count) {
                (*modes)[(*mode_count)++] = arr[i-1]; // Add to modes if frequency matches max
            }
            curr_count = 1; // Reset current count
        }
    }
    // Check the last run
    if (curr_count > max_count) {
        max_count = curr_count;
        *mode_count = 0;
        (*modes)[(*mode_count)++] = arr[n-1];
    } else if (curr_count == max_count) {
        (*modes)[(*mode_count)++] = arr[n-1];
    }
    *freq = max_count; // Set the frequency of the mode
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1; // Input validation

    int *arr = malloc(n * sizeof(int)); // Allocate memory for array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]); // Read array elements

    double m = mean(arr, n); // Calculate mean
    double med = median(arr, n); // Calculate median

    int *modes;
    int mode_count, freq;
    mode(arr, n, &modes, &mode_count, &freq); // Calculate mode

    printf("Mean: %.2f\n", m);
    printf("Median: %.2f\n", med);
    printf("Mode (%d occurrences): ", freq);
    for (int i = 0; i < mode_count; i++) {
        printf("%d ", modes[i]); // Print modes
    }
    printf("\n");

    free(arr); // Free allocated memory
    free(modes);
    return 0;
}
