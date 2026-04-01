#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, idx = 0;
    cin >> n >> k;

    char ch, wheel[26];
    fill(wheel, wheel + n, '?');
    bool isUsed[26]={false}; // 각 알파벳을 이미 사용했는지 확인하는 배열

    for (int i = 0; i < k; i++) {
        cin >> s >> ch;
        idx = (idx+s) % n; // 현재 가리키고 있는 위치 인덱스
        if (wheel[idx] == ch)
            continue;
        bool &check = isUsed[ch-'A']; // 문자 -> 숫자
        if (wheel[idx] != '?' || check) {
            cout << '!';
            return 0;
        }
        check = true;
        wheel[idx] = ch;
    }

    for (int j = idx; j>=0; j--) {
        cout << wheel[j];
    }
    for (int k = n-1; k>idx; k--)
        cout << wheel[k];

    return 0;
}