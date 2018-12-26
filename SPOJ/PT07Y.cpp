/*
   An undirected graph is tree if it has following properties.
    1) There is no cycle.
    2) The graph is connected.

   Another valid solution :
    1) m == n - 1
    2) The graph is connected.
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10004;
vector<int> adj[N];
bool vis[N];

// check if there is cycle.
bool isCyclic(int i, int parent) {
    vis[i] = 1;
    bool ret = false;
    for (int v : adj[i]) {
        if (!vis[v])
            ret |= isCyclic(v, i);
        else if (v != parent)
            return true;
    }
    return ret;
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = true;
    if (isCyclic(1, 0)) ok = false;
    else {
        // check if there is an unvisited node.
        for (int i = 1; i <= n; i++)
            if (!vis[i]) {
                ok = false;
                break;
            }
    }
    if (ok) puts("YES");
    else puts("NO");


    return 0;
}