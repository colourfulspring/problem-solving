#include <cstdio>
#include <algorithm>

using namespace std;

int a[300008];
long long result[3000008][2];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        result[0][0] = 0;
        result[0][1] = a[0];
        long long max_even = 0, max_odd = a[0];
        for (int i = 1; i < n; ++i) {
            result[i][0] = max_odd - a[i];
            result[i][1] = max(max_even, (long long)(0)) + a[i];
            max_even = max(result[i][0], max_even);
            max_odd = max(result[i][1], max_odd);
        }
        printf("%lld\n", max(max_odd, max_even));
    }
}
