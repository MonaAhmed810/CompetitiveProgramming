#include <bits/stdc++.h>

using namespace std;

const int N = 26;
vector<int> adj[N];
bool vis[N];
int src;

bool dfs(int i) {
    vis[i] = true;
    bool ret = false;
    for (int v : adj[i]) {
        if (v == src)
            return true;
        if (!vis[v])
            ret |= dfs(v);

    }
    return ret;
}

int main() {

    string s;
    while (cin >> s) {
        int u, v;
        u = s[0] - 'A';
        v = s[2] - 'A';
        adj[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        memset(vis, 0, sizeof(vis));
        src = i;
        if (dfs(i))
            printf("%c", 'A' + i);
    }

    return 0;
}