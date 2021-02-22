#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct term {
    int to_point, edge_num;

    term() {
        to_point = 0;
        edge_num = 0;
    }

    term(int t, int e) {
        to_point = t;
        edge_num = e;
    }
};

int main() {
    vector<vector<term>> tree;
    vector<int> degree;
    queue<int> que;
    vector<int> number_written_on_edge;
    int n;
    int edge_number = 0;
    scanf("%d", &n);
    tree.resize(n);
    degree.resize(n);
    number_written_on_edge.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        tree[a].emplace_back(b, i);
        degree[a]++;
        tree[b].emplace_back(a, i);
        degree[b]++;
    }
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int curr_vertex = que.front();
        for (auto &i : tree[curr_vertex]) {
            if (degree[i.to_point] != 0) {
                degree[i.to_point]--;
                number_written_on_edge[i.edge_num] = edge_number++;
                if (degree[i.to_point] == 1) {
                    que.push(i.to_point);
                }
            }
        }
        degree[curr_vertex]--;
        que.pop();
    }
    for (auto c:number_written_on_edge) {
        printf("%d\n", c);
    }
}

