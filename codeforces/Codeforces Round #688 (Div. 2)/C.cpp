#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int maxArea[10];
int rMinPos[10], rMaxPos[10];
int cMinPos[10], cMaxPos[10];
char matrix[2002][2002];

void init() {
    for (int i = 0; i < 10; ++i) {
        maxArea[i] = 0;
        rMinPos[i] = n;
        cMinPos[i] = n;
        rMaxPos[i] = -1;
        cMaxPos[i] = -1;
    }
}

void updatePos(int num, int r, int c) {
    rMaxPos[num] = max(rMaxPos[num], r);
    rMinPos[num] = min(rMinPos[num], r);
    cMaxPos[num] = max(cMaxPos[num], c);
    cMinPos[num] = min(cMinPos[num], c);
}

void updateArea(int num, int r, int c) {
    int bottom = max(n - 1 - c, c);
    int height = rMaxPos[num] == -1
                 ? 0
                 : max(abs(rMaxPos[num] - r), abs(rMinPos[num] - r));
    maxArea[num] = max(maxArea[num], bottom * height);
    bottom = max(n - 1 - r, r);
    height = cMaxPos[num] == -1
             ? 0
             : max(abs(cMaxPos[num] - c), abs(cMinPos[num] - c));
    maxArea[num] = max(maxArea[num], bottom * height);
}

void printAnswer() {
    for (int i : maxArea) {
        printf("%d ", i);
    }
    putchar('\n');
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &n);
        init();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c;
                scanf("%c", &c);
                updatePos(c - '0', i, j);
                matrix[i][j] = c;
            }
            getchar();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                updateArea(matrix[i][j] - '0', i, j);
            }
        }
        printAnswer();
    }
}
