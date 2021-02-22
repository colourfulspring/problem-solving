#include <cstdio>
#include <vector>

#define N 998244353
#define MOD(i) i % N

using namespace std;

long long pow(int a, int b) {
    long long res = 1;
    long long y = a;
    while (b != 0) {
        if (b % 2 == 1) {
            res = MOD(res * y);
        }
        y = MOD(y * y);
        b >>= 1;
    }
    return res;
}

long long inv(int a) {
    return pow(a, N - 2);
}

int main() {
    int m, n;
    vector<long long> factor;
    scanf("%d %d", &n, &m);
    factor.resize(m + 1, 1);
    for (int i = 1; i <= m; ++i) {
        factor[i] = MOD(factor[i - 1] * i);
    }
    if (n == 2) {
        printf("0");
        return 0;
    }
    long long ans = n - 2;
    ans = MOD(ans * pow(2, n - 3));
    ans = MOD(ans * factor[m]);
    ans = MOD(ans * inv(MOD(factor[n - 1] * factor[m - n + 1])));
    printf("%lld", ans);
}
