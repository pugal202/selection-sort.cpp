#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int t[50], i = l, j = m + 1, k = 0;

    while(i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while(i <= m) t[k++] = a[i++];
    while(j <= r) t[k++] = a[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        a[i] = t[k];
}

void sort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[5] = {5, 3, 4, 1, 2};

    sort(a, 0, 4);

    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";

    return 0;
}
