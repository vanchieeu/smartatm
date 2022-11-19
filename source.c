#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int result(int a[], int n, int m, int index) {
    if (m < a[n-1])
        return -1;
    if (m == 0)
        return index;

    int min = m + 1;
    int arr;
    for (int i = 0; i < n; i++) {
        int k = m%a[i]+m/a[i];

        if (k < min) {
            min = k;
            arr = a[i];
        }
    }

    result(a, n, m%arr, index+m/arr);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *a, int l, int r) {
    int p = a[(l+r)/2];

    int i = l, j = r;
    while (i < j) {
        while (a[i] > p)
            i++;

        while (a[j] < p)
            j--;
        
        if (i <= j) {
            swap(a+i, a+j);

            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(a, i, r);
    if (l < j)
        quickSort(a, l, j);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = m/a[i];
    }
    
    quickSort(a, 0, n-1);

    printf("%d", result(a, n, m, 0));
    return 0;
}