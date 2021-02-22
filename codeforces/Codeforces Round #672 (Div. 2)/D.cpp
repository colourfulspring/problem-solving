#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define MOD(i) (i) % 998244353

using namespace std;

struct term {
    int l, r;

    term(int _l, int _r) : l{_l}, r{_r} {}

    bool operator<(term t) const {
        return this->l < t.l;
    }
};

int n, k, currTime;
vector<term> lamps;
priority_queue<int, vector<int>, greater<>> lightLamps;
vector<long long> factor;
vector<long long> invFactor;

long long getInv(long long c) {
    long long ans = 1, p = 998244351;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = MOD(ans * c);
        }
        c = MOD(c * c);
        p >>= 1;
    }
    return ans;
}

int add(int a, int b) {
    return MOD(a + b);
}

int sub(int a, int b) {
    return MOD(a + (998244353 - b));
}

int combination(int a, int b) {
    if (a < b) return 0;
    return MOD(MOD(factor[a] * invFactor[b]) * invFactor[a - b]);
}

void init() {
    factor.push_back(1);
    invFactor.push_back(1);
    for (int i = 1; i < 300001; ++i) {
        factor.push_back(MOD(factor[i - 1] * i));
        invFactor.push_back(getInv(factor[i]));
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        lamps.emplace_back(l, r);
    }
    sort(lamps.begin(), lamps.end());
    init();

    int ans = 0;
    auto nextLamp = lamps.begin();
    while (nextLamp != lamps.end()) {
        currTime = nextLamp->l;
        while (!lightLamps.empty() && lightLamps.top() < currTime) {
            lightLamps.pop();
        }
        int m = lightLamps.size();

        while (nextLamp != lamps.end() && nextLamp->l == currTime) {
            lightLamps.emplace(nextLamp->r);
            ++nextLamp;
        }
        int p = lightLamps.size();
        ans = add(ans, combination(p, k));
        ans = sub(ans, combination(m, k));
    }
    printf("%d", ans);
}
