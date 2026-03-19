#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct serial{
    string num;
};

int sum(const string& s){
    int sum = 0;
    for(int i = 0; i<s.length(); i++){
        if(isdigit(s[i])){
            sum+=s[i]-'0';
        }
    }
    return sum;
}

bool comp(const serial& n1, const serial& n2){
    //길이
    if(n1.num.length() != n2.num.length()){
        return n1.num.length() < n2.num.length();
    }
    //숫자합
    int sum1 = sum(n1.num), sum2 = sum(n2.num);

    if(sum1 != sum2){
        return sum1 < sum2;
    }
    
    //사전순
    return n1.num < n2.num;
}

int main(){
    int n;
    cin >> n;

    vector<serial> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i].num;
    }

    sort(arr.begin(), arr.end(), comp);

    for(int i = 0; i < n; i++){
        cout << arr[i].num << '\n';
    }

    return 0;
}