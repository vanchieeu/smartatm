#include <iostream>
using namespace std;

int count = -1;

void cinArr(int *a, bool *b, int n) {
    for (int i = 0; i < n; i++) {
        cin >> *(a+i);
        b[i] = true;
    }
}

void Backtrack(int *a, bool *b, int n, int m, int index) {
    if (m == 0)
        return;

    for (int i = 0; i < n; i++) {
        if (b[i] && a[i] <= m) {
            b[i] = false;
            
            if (m%a[i] == 0 && index+m/a[i] < count)
                count = index + m/a[i];
            else if (m%a[i] == 0 && count == -1)
                count = index + m/a[i];

            Backtrack(a, b, n, m%a[i], index + m/a[i]);
            b[i] = true;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];
    bool check[n];
    cinArr(a, check, n);

    Backtrack(a, check, n, m, 0);
    cout << count;
    return 0;
}