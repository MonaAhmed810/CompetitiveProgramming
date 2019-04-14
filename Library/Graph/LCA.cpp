#include <bits/stdc++.h>

using namespace std;

const int N = 1003, OO = (int) 1e9;
vector<int> adj[N], e, lvl;
int h[N];
pair<int, int> sg[5 * N];

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

pair<int, int> buildSegmentTree(int idx, int l, int r) {
    if (l > r)
        return {OO, OO};
    if (l == r)
        return sg[idx] = {lvl[l], l};
    int m = (l + r) / 2;
    pair<int, int> prt1 = buildSegmentTree(2 * idx + 1, l, m);
    pair<int, int> prt2 = buildSegmentTree(2 * idx + 2, m + 1, r);
    return sg[idx] = min(prt1, prt2);
}

pair<int, int> query(int idx, int l, int r, int st, int ed) {
    if (ed < l || st > r)
        return {OO, OO};
    if (l >= st && r <= ed)
        return sg[idx];
    int m = (l + r) / 2;
    pair<int, int> prt1 = query(2 * idx + 1, l, m, st, ed);
    pair<int, int> prt2 = query(2 * idx + 2, m + 1, r, st, ed);
    return min(prt1, prt2);
}

void buildLCA() {
    dfs(1, 0, 0);
    memset(h, -1, sizeof(h));
    for (int i = 0; i < (int) e.size(); i++)
        if (h[e[i]] == -1)
            h[e[i]] = i;
    buildSegmentTree(0, 0, lvl.size() - 1);
}

int getLCA(int x, int y) {
    if (h[x] > h[y])
        swap(x, y);
    return e[query(0, 0, lvl.size() - 1, h[x], h[y]).second];
}