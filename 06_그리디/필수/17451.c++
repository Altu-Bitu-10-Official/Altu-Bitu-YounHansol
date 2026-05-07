#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    long long answer = 0;
    cin >> n;

    vector<long long> v(n);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for(int i = n-1; i >=1; i--){//역으로 계산
        if(v[i+1] > v[i]){//현재랑 다음이랑 비교
            if(v[i+1]%v[i] == 0){ //현재랑 다음이랑 나누어떨어지면 +1 안함
                answer = v[i+1]/v[i];
            }
            else{
                answer = v[i+1]/v[i] +1; //다음을 현재로 나누고 몫에 +1하면 정수배 얼마나 해야하는지 구함
            }
            v[i] *= answer;//현재에 곱해서 속도 최솟값 구해주기
        }
    }

    cout << v[1];
    return 0;
}