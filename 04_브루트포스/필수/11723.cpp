#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m, x;
    string str = "";
    int S = 0;

    cin >> m;
    while(m--){//m이 0이될때까지 반복
        cin >> str;
        if(str == "add"){
            cin >> x;
            S |= (1<<x);//몇 번째 위치에 1이 생성되는지에 따라 x의 값을 인식
        }

        else if(str == "remove"){
            cin >> x;
            S &= ~(1<<x);
        }

        else if(str == "check"){
            cin >> x;
            if(S & (1 << x)){
                cout << 1 <<'\n';
            }
            else{
                cout << 0 << '\n';
            }
        }

        else if(str == "toggle"){
            cin >> x;
            if(S & (1 << x)){
                S &= ~(1<<x);
            }
            else{
                S |= (1<<x);
            }
        }

        else if(str == "all"){
            S = (1 << 21) - 1;
        }
        
        else if(str == "empty"){
            S = 0;
        }
    }
    return 0;
}