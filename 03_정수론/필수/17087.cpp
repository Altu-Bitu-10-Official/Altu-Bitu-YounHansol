#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 유클리드 호제법을 이용해 최대 공약수 구하기
int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, a;
    cin >> n >> s;
    vector<int> dist; // 수빈이와 동생들 간 거리 차이

    for (int i = 0; i < n; i++) {
        cin >> a;
        dist.push_back(abs(s-a));
    }
    int ans = dist[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, dist[i]);
    }
    cout << ans;
    return 0;
}