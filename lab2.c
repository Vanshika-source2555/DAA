#include <stdio.h>
#include <time.h>   // for clock()
#define SIZE 10

// ---------- Merge Sort ----------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[SIZE], R[SIZE];  // fixed arrays (safe since SIZE=10)
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ---------- Quick Sort ----------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = t;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------- Utility ----------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[SIZE], arr2[SIZE];

    printf("Enter %d elements for Merge Sort:\n", SIZE);
    for (int i = 0; i < SIZE; i++) scanf("%d", &arr1[i]);

    printf("Enter %d elements for Quick Sort:\n", SIZE);
    for (int i = 0; i < SIZE; i++) scanf("%d", &arr2[i]);

    clock_t start, end;
    double cpu_time;

    // ---------- Merge Sort ----------
    start = clock();
    mergeSort(arr1, 0, SIZE - 1);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted with Merge Sort:\n");
    printArray(arr1, SIZE);
    printf("Time taken by Merge Sort: %f seconds\n", cpu_time);

    // ---------- Quick Sort ----------
    start = clock();
    quickSort(arr2, 0, SIZE - 1);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted with Quick Sort:\n");
    printArray(arr2, SIZE);
    printf("Time taken by Quick Sort: %f seconds\n", cpu_time);
 return 0;
}
