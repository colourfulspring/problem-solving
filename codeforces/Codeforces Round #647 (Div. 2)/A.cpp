#include <cstdio>

long long gcd(long long a, long long b) {
    long long c;
    while (a % b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int check(long long a) {
    int c = 0;
    while (a % 2 == 0) {
        c++;
        a >>= 1;
    }
    if (a == 1) {
        return c;
    } else {
        return -1;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, c;
        int apos, bpos;
        scanf("%lld %lld", &a, &b);
        if (b > a) {
            c = b;
            b = a;
            a = c;
        }
        c = gcd(a, b);
        a /= c;
        b /= c;
        apos = check(a);
        bpos = check(b);
        if (apos == -1 || bpos == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", (apos - bpos + 2) / 3);
        }
    }
    return 0;
}
