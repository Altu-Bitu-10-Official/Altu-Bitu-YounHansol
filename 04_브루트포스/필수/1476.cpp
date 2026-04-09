#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int e, s, m;
    int y = 1;//년도
    cin >> e >> s >> m;

    while(true){
        if((y-e)%15 == 0 && (y-s)%28 == 0 && (y-m)%19 == 0){//y가 16일때 e는 1, 16-1 = 15, 15%15 = 0
            cout << y << '\n';
            break;
        }
        y++;
    }
    return 0;
}