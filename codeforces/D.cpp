#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int b[400003];
int oneMoreThanZero;
int zeroMoreThanOne;

void init() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        b[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        --t;
        b[t] = 1;
    }
    oneMoreThanZero = 0;
    zeroMoreThanOne = 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();

        int num[2] = {0, 0};
        for (int i = 0; i < 2 * n; ++i) {
            ++num[b[i]];
            zeroMoreThanOne = max(zeroMoreThanOne, num[0] - num[1]);
            oneMoreThanZero = max(oneMoreThanZero, num[1] - num[0]);
        }
        printf("%d\n", n + 1 - zeroMoreThanOne - oneMoreThanZero);
    }
}
