#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k;
        bool flag = false;
        scanf("%lld %lld", &n, &k);
        if (n >= k * k && (n + k) % 2 == 0) {
            flag = true;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
}

