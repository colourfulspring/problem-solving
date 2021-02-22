#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> expectation;
vector<int> result;
int len;

void init() {
    long long num = 2;
    do {
        expectation.emplace_back(num);
        num *= 2;
        num += 2;
    } while (num < 1000000000000000000);
}

int main() {
    int t;
    scanf("%d", &t);
    init();
    while (t--) {
        long long k;
        scanf("%lld", &k);
        if (k % 2 == 1) {
            printf("-1\n");
            continue;
        }

        len = 0;
        result.clear();
        while (k != 0) {
            auto it = upper_bound(expectation.begin(), expectation.end(), k);
            --it;
            k -= *it;
            int dx = it - expectation.begin();
            result.emplace_back(dx);
            len += dx;
        }

        printf("%d\n", len + result.size());
        for (auto c:result) {
            printf("1 ");
            while (c--) {
                printf("0 ");
            }
        }
        putchar('\n');
    }
}
