#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

const int INF = 1e9;

vector<int> dijkstra(int start, vector<vector<ci>> &graph) {
    vector<int> dist(graph.size(), INF);
    priority_queue<ci, vector<ci>, greater<ci>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (ci next : graph[curNode]) {
            int nextNode = next.first;
            int nextDist = curDist + next.second;

            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<ci>> graph(n + 1);
    vector<vector<ci>> reverseGraph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        graph[a].push_back({b, t});
        reverseGraph[b].push_back({a, t});
    }

    vector<int> distFromX = dijkstra(x, graph);
    vector<int> distToX = dijkstra(x, reverseGraph);

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        answer = max(answer, distFromX[i] + distToX[i]);
    }

    cout << answer << '\n';

    return 0;
}