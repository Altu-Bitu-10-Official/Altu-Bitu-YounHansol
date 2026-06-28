#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> eaten(d + 1, 0);

    int cnt = 0;


    for (int i = 0; i < k; i++) {
        if (eaten[belt[i]] == 0) {
            cnt++;//n번째 초밥을 처음 먹으면 카운트
        }
        eaten[belt[i]]++;//n번째 초밥 먹은거 카운트
    }

    int answer = cnt;
    //초기 배열에서 쿠폰 초밥 먹었는지 확인
    if (eaten[c] == 0) {
        answer++;
    }


    for (int i = 1; i < n; i++) {
        //2차배열이어서 변수에 먼저 저장 후 처리
        int remove = belt[i - 1];
        int add = belt[(i + k - 1) % n];


        eaten[remove]--;

        if (eaten[remove] == 0) {
            cnt--;
        }

        if (eaten[add] == 0) {
            cnt++;
        }

        eaten[add]++;


        int current = cnt;

        //이후 배열에서 쿠폰 초밥 먹었는지 확인
        if (eaten[c] == 0) {
            current++;
        }

        if (current > answer) {
            answer = current;
        }
    }

    return answer;
}

int main() {
    int n, d, k, c;

    cin >> n >> d >> k >> c;

    vector<int> belt(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    cout << solution(n, d, k, c, belt);

    return 0;
}