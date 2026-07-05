#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int parent, vector<vector<int>> &tree, vector<int> &subtreeSize) {
    subtreeSize[node] = 1;

    for (int next : tree[node]) {
        if (next == parent) continue;

        dfs(next, node, tree, subtreeSize);
        subtreeSize[node] += subtreeSize[next];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> tree(n + 1);
    vector<int> subtreeSize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(r, 0, tree, subtreeSize);

    while (q--) {
        int u;
        cin >> u;
        cout << subtreeSize[u] << '\n';
    }

    return 0;
}