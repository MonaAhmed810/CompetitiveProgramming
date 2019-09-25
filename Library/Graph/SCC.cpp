// SCC
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200005;
int n, num_of_components, scc[N];
stack<int> s;
vector<int> adj[N], reversed_adj[N], component[N];
bool vis[N];

void fill_order(int i) {
    vis[i] = 1;
    for (int v: adj[i])
        if (!vis[v])
            fill_order(v);
    s.push(i);
}

void dfs(int i, int c) {
    vis[i] = 1;
    component[c].push_back(i);
    scc[i] = c;
    for (int v:reversed_adj[i])
        if (!vis[v])
            dfs(v, c);
}

void SCC() {
    // store graph & its reversed graph
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            fill_order(i);
    memset(vis, 0, sizeof vis);
    num_of_components = 0;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (!vis[v]) {
            dfs(v, num_of_components);
            ++num_of_components;
        }
    }
}
