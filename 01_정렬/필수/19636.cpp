#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int w0, i0, t;//다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량, 기초 대사량 변화 역치
    cin >> w0 >> i0 >> t;

    int d, i1, a; //다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 다이어트 기간 일일 활동 대사량
    cin >> d >> i1 >> a;

    int w1 = w0+(i1-i0-a)*d;//일일 기초대사량 고려 안한 예상 체중
    int w2 = w0;//기초대사량 고려 예상 체중
    int i2 = i0;//다이어트 후 기초대사량

    if(w1 <= 0){
        cout << "Danger Diet" << '\n';
    }
    else{
        cout << w1 << ' ' << i0 <<'\n';
    }

    for(int i = 1; i <= d; i++){
        //기초대사량 고려 예상 체중, 다이어트 후 기초대사량 계산
        int sum = i1 - (i2 + a);
        w2+=sum;
        if(abs(sum) > t){
            i2 += floor(sum/2.0);//int여서 답이 틀렸었다.
        }
    }

    int after_i = i0-(i2+0);

    if(i2 <= 0 || w2 <= 0){
        cout << "Danger Diet";
    }
    else if(after_i > 0){
        cout << w2 << ' ' << i2 << ' ' << "YOYO";
    }
    else if(after_i <= 0) {
        cout << w2 << ' ' << i2 << ' ' << "NO";
    }

    return 0;
}