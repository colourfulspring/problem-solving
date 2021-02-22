#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[200003];

long long getVal(int i) {
    if (i == 0) {
        return abs(a[1] - a[0]);
    }
    if (i == n - 1) {
        return abs(a[n - 1] - a[n - 2]);
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1] || a[i] > a[i - 1] && a[i] > a[i + 1]) {
        return 2 * min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long tot = 0, maxVal = -1;
        scanf("%d", &n);
        scanf("%d", a);
        for (int i = 1; i < n; ++i) {
            scanf("%d", a + i);
            tot += abs(a[i] - a[i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, getVal(i));
        }
        printf("%lld\n", tot - maxVal);
    }
}
