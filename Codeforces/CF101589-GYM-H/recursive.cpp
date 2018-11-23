#include <bits/stdc++.h>

using namespace std;

const int N = 51, OO = 1e9, MAX = 5300;
int n, a[N], tot, optimal, memo[N][N][MAX];
vector<int> path;

int go(int i, int prev, int perimeter) {
    if (i == n + 1) {
        if (perimeter + a[prev] >= tot / 2)
            return 0;
        return -OO;
    }
    int &ret = memo[i][prev][perimeter];
    if (ret != -1)
        return ret;
    int take = a[i] + go(i + 1, prev, perimeter);
    int leave = go(i + 1, i, perimeter + abs(a[prev] - a[i]) + 2);
    return ret = max(take, leave);
}

void build_path(int i, int prev, int perimeter) {
    if (i == n + 1)
        return;
    int take = a[i] + go(i + 1, prev, perimeter);
    int leave = go(i + 1, i, perimeter + abs(a[prev] - a[i]) + 2);
    if (optimal == take) {
        path.push_back(i);
        optimal -= a[i];
        build_path(i + 1, prev, perimeter);
    } else
        build_path(i + 1, i, perimeter + abs(a[prev] - a[i]) + 2);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(memo, -1, sizeof(memo));
    int prev = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tot += abs(a[i] - prev) + 2;
        prev = a[i];
    }
    tot += prev;

    optimal = go(1, 0, 0);
    printf("%d\n", optimal);
    build_path(1, 0, 0);
    printf("%d\n", (int) path.size());
    for (int x : path)
        printf("%d ", x);

    return 0;
}