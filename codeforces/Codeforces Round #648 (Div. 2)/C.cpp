#include <cstdio>

int main() {
    int n;
    int a[200000], b[200000];
    scanf("%d", &n);
    int temp, max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp - 1] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        b[temp - 1] = i;
    }
    // a[i] means offset of number i
    for (int i = 0; i < n; i++) {
        a[i] = (b[i] >= a[i]) ? b[i] - a[i] : b[i] + n - a[i];
        b[i] = 0;
    }
    // b[i] means the number of occurences of offset i
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    //the answer
    for (int i = 0; i < n; i++) {
        max = (b[i] > max) ? b[i] : max;
    }
    printf("%d", max);
    return 0;
}
