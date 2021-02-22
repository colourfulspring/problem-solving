#include <cstdio>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

int n;
vector<int> time, x;
long long tot;
long long goal, currPos;
long long currTime, arriveTime;

void read() {
    scanf("%d", &n);
    time.clear();
    x.clear();
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        time.emplace_back(a);
        x.emplace_back(b);
    }
    tot = 0;
    currTime = 0;
    currPos = 0;
    arriveTime = 0;
    goal = 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        read();

        for (int i = 0; i < time.size(); ++i) {
            long long nextTime = (i == time.size() - 1) ? LLONG_MAX : time[i + 1];
            if (time[i] < arriveTime) {
                if (goal < currPos) {
                    currPos -= (time[i] - currTime);
                } else {
                    currPos += (time[i] - currTime);
                }
                currTime = time[i];
            } else {
                currPos = goal;
                currTime = time[i];
                goal = x[i];
                arriveTime = currTime + abs(goal - currPos);
            }

            long long canArrivePos;
            if (goal < currPos) {
                canArrivePos = currPos - (nextTime - currTime);
                if (canArrivePos < goal) canArrivePos = goal;
                if (canArrivePos <= x[i] && x[i] <= currPos) tot++;
            } else {
                canArrivePos = currPos + (nextTime - currTime);
                if (canArrivePos > goal) canArrivePos = goal;
                if (canArrivePos >= x[i] && x[i] >= currPos) tot++;
            }
        }
        printf("%lld\n", tot);
    }
}
