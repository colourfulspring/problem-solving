#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> isUsed;
vector<int> answer;

void init() {
    scanf("%d", &n);
    graph.resize(n);
    for (auto &c:graph) {
        c.clear();
    }
    isUsed.clear();
    isUsed.resize(n, 0);
    answer.clear();
    answer.resize(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
}

int dfs(int i) {
    isUsed[i] = 1;

    int minPath = INT_MAX, maxPath = 0;
    int childNum = 0;
    for (auto v:graph[i]) {
        if (!isUsed[v]) {
            ++childNum;
            int ans = dfs(v);
            if (ans < minPath) {
                minPath = ans;
            }
            if (ans > maxPath) {
                maxPath = ans;
            }
        }
    }
    if (childNum == 0) {
        answer[i] = 0;
        return 0;
    } else if (childNum == 1) {
        answer[i] = answer[i] + 1;
        return minPath + 1;
    } else {
        answer[i] = max(maxPath + 2, answer[i]);
        return minPath + 1;
    }
}

void dfs0(int i) {
    isUsed[i] = 1;

    int maxPath = 0, secondMaxPath = 0;
    int childNum = 0;
    for (auto v:graph[i]) {
        if (!isUsed[v]) {
            ++childNum;
            int ans = dfs(v);
            if (ans > maxPath) {
                secondMaxPath = maxPath;
                maxPath = ans;
            } else if (ans > secondMaxPath) {
                secondMaxPath = ans;
            }
        }
    }
    if (childNum == 0) {
        answer[i] = 0;
    } else if (childNum == 1) {
        answer[i] = maxPath + 1;
    } else {
        answer[i] = max(maxPath + 1, secondMaxPath + 2);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();

        dfs0(0);

        int ans = 0;
        for (auto c:answer) {
            ans = max(ans, c);
        }

        printf("%d\n", ans);
    }
}
