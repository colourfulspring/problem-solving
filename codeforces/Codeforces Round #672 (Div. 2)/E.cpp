#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int squareSum = 0;
vector<int> initialArray;
vector<int> preSumOfArray;
int dp[84][84][3570];

void minimum(int &a, const int &b) {
    a = min(a, b);
}

void read() {
    int numOfZero = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            ++numOfZero;
        } else {
            initialArray.emplace_back(numOfZero);
            numOfZero = 0;
        }
    }
    initialArray.emplace_back(numOfZero);

    preSumOfArray.emplace_back(initialArray.front());
    for (auto it = ++initialArray.begin(); it != initialArray.end(); ++it) {
        preSumOfArray.emplace_back(preSumOfArray.back() + *it);
    }
    squareSum = preSumOfArray.back() * preSumOfArray.back();
}

void init() {
    for (auto & i : dp) {
        for (auto & j : i) {
            for (int & k : j) {
                k = INT_MAX;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    read();

    int nums = initialArray.size();
    int sum = preSumOfArray.back();

    init();
    dp[0][0][0] = 0;
    for (int i = 0; i < nums; ++i) {
        for (int j = 0; j <= sum; ++j) {
            for (int k = 0; k <= n * (n - 1) / 2; ++k) {
                if (dp[i][j][k] == INT_MAX) continue;
                for (int h = 0; h <= sum - j; ++h) {
                    minimum(dp[i + 1][j + h][k + abs(preSumOfArray[i] - (j + h))], dp[i][j][k] + h * h);
                }
            }
        }
    }

    int val = INT_MAX;
    for (int i = 0; i <= n * (n - 1) / 2; ++i) {
        if (dp[nums][sum][i] != INT_MAX) {
            val = min(val, dp[nums][sum][i]);
        }
        printf("%d ", (squareSum - val) / 2);
    }
}
