#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<int> q;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){//배열에 입력
        q.push(i);
    }

    while(q.size() != 1){//1이 될때까지 반복
        q.pop();
        //front rear로 옮기기
        q.push(q.front());
        //front옮긴 후 기존 front 지우기
        q.pop();
    }

    cout << q.front();

    return 0;
}