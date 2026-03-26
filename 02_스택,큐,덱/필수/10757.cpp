#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<int> ch1;
    stack<int> ch2;
    stack<int> ch3;


    string a, b;
    cin >> a >> b;

    int carry = 0, n = 0;

    for(int i = 0; i < a.size(); i++){
        ch1.push(a[i]-'0');
    }

    for(int i = 0; i < b.size(); i++){
        ch2.push(b[i]-'0');
    }

    while(!ch1.empty() && !ch2.empty()){
        n = ch1.top()+ch2.top()+carry;
        if( n >= 10){
            n = n%10;
            ch3.push(n);
            carry = 1;
        }

        else{
            carry = 0;
            ch3.push(n);
        }

        ch1.pop();
        ch2.pop();

    }

    if(!ch1.empty() && ch2.empty()){
        while(!ch1.empty()){
            n = ch1.top()+carry;
            if( n >= 10){
                n = n%10;
                ch3.push(n);
                carry = 1;
            }

            else{
                carry = 0;
                ch3.push(n);
            }
            ch1.pop();
        }
    }

    else if(!ch2.empty() && ch1.empty()){
        while(!ch2.empty()){
            n = ch2.top()+carry;
            if( n >= 10){
                n = n%10;
                ch3.push(n);
                carry = 1;
            }

            else{
                carry = 0;
                ch3.push(n);
            }
            ch2.pop();
        }
    }

    if(carry == 1){
        ch3.push(carry);
    }
    while(!ch3.empty()){
        cout << ch3.top();
        ch3.pop();
    }


}