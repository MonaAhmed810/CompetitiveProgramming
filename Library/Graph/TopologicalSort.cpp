// TopologicalSort
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector<int> adj[N];
bool vis[N];
stack<int> topoStack;

void topologicalSort(int i) {
    vis[i] = true;
    for (int v : adj[i])
        if (!vis[v])
            topologicalSort(v);
    topoStack.push(i);
}
