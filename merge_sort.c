#include <stdio.h>

// Merge function to combine two sorted halves into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left half
    int n2 = right - mid;     // Size of the right half

    // Create temporary arrays for the two halves
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoid overflow for large indices

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // Example array of 51 numbers
    int arr[51] = {45, 23, 89, 12, 78, 34, 56, 90, 11, 5, 43, 22, 88, 14, 77, 33, 55, 91, 10, 4, 
                   42, 21, 87, 13, 76, 32, 54, 92, 9, 3, 41, 20, 86, 15, 75, 31, 53, 93, 8, 2, 
                   40, 19, 85, 16, 74, 30, 52, 94, 7, 1, 50};
    
    int size = 51;

    printf("Original array:\n");
    printArray(arr, size);

    // Sort the array
    mergeSort(arr, 0, size - 1);

    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}
