#include <bits/stdc++.h>

using namespace std;

const int N = 2003, K = 12;
vector<int> adj[N];
vector<int> e, lvl, h;
int sz, lg[N];
pair<int, int> st[N][K];

void dfs(int i, int parent, int level) {
    e.push_back(i);
    lvl.push_back(level);
    for (int v : adj[i]) {
        if (v != parent) {
            dfs(v, i, level + 1);
            e.push_back(i);
            lvl.push_back(level);
        }
    }
}

void calcLogs() {
    lg[1] = 0;
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
}

void buildSparse() {
    for (int i = 0; i < sz; i++)
        st[i][0] = {lvl[i], e[i]};
    for (int j = 1; j <= lg[sz]; j++)
        for (int i = 0; i + (1 << j) - 1 < sz; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    int j = lg[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]).second;
}


void buildLCA() {
    dfs(1, 0, 0);
    sz = (int) e.size();
    h.resize(e.size(), -1);
    for (int i = 0; i < sz; i++)
        if (h[e[i]] == -1)
            h[e[i]] = i;
    buildSparse();
}

int getLCA(int x, int y) {
    if (h[x] > h[y])
        swap(x, y);
    return query(h[x], h[y]);
}