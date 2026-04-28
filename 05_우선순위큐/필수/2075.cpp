#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; //최소힙 사용해서 top에 제일 작은 값 오게 하기

    for(int i = 1; i <= n*n; i++){
        cin >> x;
        pq.push(x);
        if(pq.size() > n)//n보다 사이즈가 커지면 제일 작은값 없애기
            pq.pop();
    }

    cout << pq.top() << "\n";

    return 0;
}