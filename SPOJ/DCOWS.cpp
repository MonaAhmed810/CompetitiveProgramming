/*
    DP - minimization problem
    
    First:
        sort the bulls and cows heights.
    Second:
        run DP (take or leave)
    
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5003;
const ll OO = 1e18;
int n, m, a[N], b[N];
ll memo[N][N];

ll go(int i, int j) {
    if (i == n)
        return 0;
    if (j == m)
        return OO;
    ll &ret = memo[i][j];
    if (ret != -1)
        return ret;
    ll take = abs(a[i] - b[j]) + go(i + 1, j + 1);
    ll leave = go(i, j + 1);
    return ret = min(take, leave);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    memset(memo, -1, sizeof(memo));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    printf("%lld", go(0, 0));

    return 0;
}