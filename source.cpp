#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int b[m+1];
    for (int i = 0; i < m+1; i++) {
        b[i] = 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }

    for (int i = a[0]; i < m+1; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] < 0)
                continue;
            if (b[i] == 0 && b[i-a[j]] != 0)
                b[i] = b[i-a[j]] + 1;
            else if (b[i-a[j]] != 0 && b[i] != 0 && b[i-a[j]] +1 < b[i])
                b[i] = b[i-a[j]] + 1;
        }
    }

    if (b[m] != 0)
        cout << b[m];
    else 
        cout << -1;
    return 0;
}