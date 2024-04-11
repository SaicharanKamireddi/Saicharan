#include <stdio.h>

#define SIZE 10

int input[SIZE] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};

void menu() {
    printf("\n1. Insertion Sort \n2. Merge Sort \n3. Quick Sort \n4. Selection Sort  \n5. Shell Sort  \n6. Heap Sort  \n9. Exit");
}

void print_array() {
    printf("\nElements after sorting are ...\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\t", input[i]);
    printf("\n");
}

void insertion_sort() {
    for (int i = 1; i < SIZE; i++) {
        int key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > key) {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
        print_array();
    }
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        print_array();
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void selection_sort() {
    for (int i = 0; i < SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (input[j] < input[min_idx])
                min_idx = j;
        }
        int temp = input[min_idx];
        input[min_idx] = input[i];
        input[i] = temp;
        print_array();
    }
}

void shell_sort() {
    for (int gap = SIZE / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < SIZE; i++) {
            int temp = input[i];
            int j;
            for (j = i; j >= gap && input[j - gap] > temp; j -= gap)
                input[j] = input[j - gap];
            input[j] = temp;
        }
        print_array();
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort() {
    for (int i = SIZE / 2 - 1; i >= 0; i--)
        heapify(input, SIZE, i);

    for (int i = SIZE - 1; i > 0; i--) {
        int temp = input[0];
        input[0] = input[i];
        input[i] = temp;
        heapify(input, i, 0);
    }
}

int main() {
    int choice = 0;
    menu();
    printf("\nSelect the sorting technique: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("\n**Insertion Sort**");
        insertion_sort();
        break;
    case 2:
        printf("\n**Merge Sort**");
        merge_sort(input, 0, SIZE - 1);
        break;
    case 3:
        printf("\n**Quick Sort**");
        quick_sort(input, 0, SIZE - 1);
        break;
    case 4:
        printf("\n**Selection Sort**");
        selection_sort();
        break;
    case 5:
        printf("\n**Shell Sort**");
        shell_sort();
        break;
    case 6:
        printf("\n**Heap Sort**");
        heap_sort();
        break;
    case 9:
        return 0;
    default:
        printf("Invalid choice");
    }
    print_array();
    return 0;
}

/*Observations
This program helps understand the different sorting tecniques*/
