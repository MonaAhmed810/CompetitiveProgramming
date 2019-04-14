#include <bits/stdc++.h>

using namespace std;

const int N = 100005, K = 20;
int n, a[N], st[N][K], lg[N];

void calcLogs() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
}

void buildSparse() {
    calcLogs();
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j <= lg[n]; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    int j = lg[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}