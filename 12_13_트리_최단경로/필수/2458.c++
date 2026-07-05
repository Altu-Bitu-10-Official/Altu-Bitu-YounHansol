#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> height(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        height[a][b] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                height[i][j] = height[i][j] || (height[i][k] && height[k][j]);
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (height[i][j] || height[j][i]) {
                cnt++;
            }
        }

        if (cnt == n - 1) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}