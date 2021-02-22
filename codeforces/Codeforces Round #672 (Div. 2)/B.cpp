#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long a[35] = {0};
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int temp;
            scanf("%d", &temp);
            int k = 0;
            while (temp > 1) {
                temp >>= 1;
                ++k;
            }
            ++a[k];
        }
        long long sum = 0;
        for (long long i : a) {
            if (i >= 2) {
                sum += i * (i - 1) / 2;
            }
        }
        printf("%lld\n", sum);
    }
}
