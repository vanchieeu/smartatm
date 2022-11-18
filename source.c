#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void Backtrack(int *a, bool *b, int n, int m, int index) {
    for (int i = 0; i < n; i++) {
        if (b[i] && a[i] <= m) {
            b[i] = false;

            if (m%a[i] == 0) {
                printf("%d", index+m/a[i]);
                exit(0);
            }

            Backtrack(a, b, n, m%a[i], index+m/a[i]);
            b[i] = true;
        }
    }
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
    bool b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = true;
    }
    
    quickSort(a, 0, n-1);

    Backtrack(a, b, n, m, 0);

    printf("-1");
    return 0;
}