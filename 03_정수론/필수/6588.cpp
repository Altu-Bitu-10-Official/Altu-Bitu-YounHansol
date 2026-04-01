#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 에라토스테네스의 체를 이용한 소수 여부 반환 함수
vector<bool> primeNumbers(int n) {
    vector<bool> is_prime(n+1, true); // 0~n: 모두 소수라고 가정
    is_prime[0] = is_prime[1] = false; // 0, 1은 소수 아님
    for (int i = 2; i*i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) { //i의 배수들 제거
            is_prime[j] = false;
        }
    }
    return is_prime;
}

int goldbach(int n, vector<bool> &is_prime) {
    for (int k = 3; k <= n/2; k++) {
        // 2는 짝수 소수라서 제외
        if (is_prime[k]&&is_prime[n-k])
            return k;
    }
    // 만족하는 소수 없음
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>arr;
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        arr.push_back(n);
    }
    int max_n = *max_element(arr.begin(), arr.end()); //n의 최댓값을 기준으로 소수 배열 생성
    vector<bool> is_prime = primeNumbers(max_n);

    for (int i = 0; i < arr.size(); i++) {
        int a = goldbach(arr[i], is_prime);

        if (a!=0) // a, b 존재
            cout << arr[i]<<" = "<< a << " + " << arr[i]-a<< '\n';
        else
            cout<< "Goldbach's conjecture is wrong." << '\n';
    }
    return 0;
}