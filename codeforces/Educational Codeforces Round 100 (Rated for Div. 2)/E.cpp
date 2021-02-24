#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, k;
vector<set<int>> graphReduced;
vector<int> inDegReduced;
vector<int> nextV;
vector<int> result;
vector<int> parent;

int getParent(int v) {
    if (parent[v] == v) return v;
    parent[v] = getParent(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int aP = getParent(a);
    int bP = getParent(b);
    if (aP != bP) {
        parent[bP] = aP;
        inDegReduced[aP] += inDegReduced[bP];
        inDegReduced[bP] = 0;
    }
}

bool init() {
    vector<vector<int>> graph;
    vector<int> inDeg;

    scanf("%d %d", &n, &k);
    graph.resize(n);
    graphReduced.resize(n);
    nextV.resize(n, -1);
    inDegReduced.resize(n, 0);
    inDeg.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent.emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
        int s;
        scanf("%d", &s);
        --s;
        if (s != -1) {
            graph[s].emplace_back(i);
            ++inDeg[i];
        }
    }

    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        nextV[a] = b;
        merge(a, b);
        graph[a].emplace_back(b);
        ++inDeg[b];
    }

    queue<int> que;
    int usedNum = 0;
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            que.push(i);
            ++usedNum;
        }
    }
    while (!que.empty()) {
        int vertex = que.front();
        que.pop();
        for (auto c:graph[vertex]) {
            --inDeg[c];
            if (inDeg[c] == 0) {
                que.push(c);
                ++usedNum;
            }
        }
    }
    if (usedNum < n) {
        putchar('0');
        return false;
    }


    for (int i = 0; i < n; ++i) {
        int iP = getParent(i);
        for (auto c:graph[i]) {
            int cP = getParent(c);
            if (iP != cP && graphReduced[iP].find(cP) == graphReduced[iP].end()) {
                graphReduced[iP].insert(cP);
                ++inDegReduced[cP];
            }
        }
    }
    return true;
}

void printAnswer() {
    for (auto c:result) {
        printf("%d ", ++c);
    }
}

void deleteV(int v, queue<int> &q) {
    for (auto c:graphReduced[v]) {
        --inDegReduced[c];
        if (inDegReduced[c] == 0) {
            q.push(c);
        }
    }
}

bool topo(queue<int> &q) {
    if (q.empty()) {
        if(result.size() == n){
            printAnswer();
        }else{
            putchar('0');
        }
        return false;
    }

    int vertex = q.front();
    q.pop();
    deleteV(vertex, q);
    while (true) {
        result.emplace_back(vertex);
        if (nextV[vertex] == -1) break;
        vertex = nextV[vertex];
    }
    return true;
}

int main() {
    if (!init()) {
        return 0;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (i == getParent(i) && inDegReduced[i] == 0) {
            q.push(i);
        }
    }
    while (topo(q));
    return 0;
}
