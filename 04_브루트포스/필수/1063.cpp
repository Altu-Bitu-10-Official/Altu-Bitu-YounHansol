#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<char, char> pos;//좌표 저장 벡터

//input값에 따라 좌표 위치를 바꿔주는 함수
//문자 하나하나 처리하기, input이 LT면, L, T 따로 처리
pos movePos(string input, char x, char y){
    for(char how : input) {
        if(how == 'R'){
            x++;
        }
        else if (how == 'L'){
            x--;
        }
        else if(how == 'T'){
            y++;
        }
        else{
            y--;
        }
    }
    return {x, y};
}

//두 좌표의 위치 일치 확인
bool isSame(pos a, pos b){
    return a == b;
}

//체스판에서 움직이는지 확인
bool isInsideBoard(pos p){
    return (p.first >= 'A' && p.first <= 'H' && p.second >= '1' && p.second <= '8');
}

int main(){
    pos k, s;
    int n;
    string input;

    cin >> k.first >> k.second >> s.first >> s.second >> n;

    while(n--){
        cin >> input;
        
        //움직인 후 k,s의 위치
        pos next_k, next_s;

        next_k = movePos(input, k.first, k.second);

        if(isSame(next_k, s)){
            next_s = movePos(input, s.first, s.second);
        }
        else{
            next_s = s;
        }

        if(isInsideBoard(next_k) && isInsideBoard(next_s)){
            k = next_k;
            s = next_s;
        }
    }
    cout << k.first << k.second << '\n';
    cout << s.first << s.second << '\n';

    return 0;
}