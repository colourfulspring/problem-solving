#include <cstdio>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int flag[50][50] = {0};
char a[50][50];
int tot_good, find_good, find_bad;

void dfs(int px, int py) {
    if (a[px][py] == '#')
        return;
    flag[px][py] = 1;
    for (int k = 0; k < 4; k++) {
        int x = px + dx[k];
        int y = py + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && !flag[x][y]) {
            if (a[x][y] == 'G')
                find_good++;
            if (a[x][y] == 'B')
                find_bad++;
            dfs(x, y);
        }
    }
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        tot_good = 0;
        find_good = 0;
        find_bad = 0;
        scanf("%d %d\n", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flag[i][j] = 0;
                char c = '\n';
                for (; c == '\n'; scanf("%c", &c))
                    ;
                a[i][j] = c;
                if (a[i][j] == 'G')
                    tot_good++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m &&
                            a[x][y] == '.') {
                            a[x][y] = '#';
                        }
                    }
                }
            }
        }
        dfs(n - 1, m - 1);
        printf(tot_good == find_good  && !find_bad ? "YES\n" : "NO\n");
    }
}
