#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, answer = 0;
    cin >> n >> k;

    vector<char> hp(n);

    for(int i = 0; i < n; i++){
        cin >> hp[i];
    }

    for(int i = 0; i < n; i++){
        if(hp[i] != 'P'){//hp[i]가 P일때 루프 시작
            continue;
        }
        for(int j = i-k; j<= i+k; j++){
            if(hp[j] == 'H' && j >0 && j <= n){
                hp[j] = 'X';
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}