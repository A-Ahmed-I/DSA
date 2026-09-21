# Sorting

> Sorting is arranging elements in a specific order.

---

## Why Sorting?

Sorting is fundamental in computer science. It makes data easier to:

- **Search** — binary search requires sorted data
- **Analyze** — finding min, max, median is trivial
- **Display** — user-facing lists feel natural when ordered

---

## Types of Sorting

### 1 — Naive Sorting

A naive sorting approach compares each element with all other elements and swaps immediately whenever a smaller element is found. This is an inefficient implementation of selection sort but is simple to understand.

**Time Complexity:**

- Best case: O(n²)
- Worst case: O(n²)
- Space: O(1) — in-place

**How it works:**

```cpp
int num[n] = {};

for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        if (num[j] < num[i]) {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
    }
}
```

### 2- Merge sort

Merge sort is a divide-and-conquer sorting algorithm that divides the array into smaller subarrays, sorts them recursively, and then merges the sorted subarrays back together.

**Time Complexity:**

- Best case: O(n log n)
- Worst case: O(n log n)
- Space: O(n) — extra array needed

**How it works:**

1- Divide the array into two halves
2- Recursively sort each half
3- Merge the two sorted halves into one sorted array

```cpp
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
```
