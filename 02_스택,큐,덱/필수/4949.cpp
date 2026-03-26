#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;

    while(true){

        getline(cin, str);
        if(str == "."){
            break;
        }

        stack<char> ch;
        bool result = true;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '['){
                ch.push(str[i]);
            }

            if(str[i] == ')'){
                if(ch.empty() || ch.top() != '('){
                    result = false;
                    break;
                }
                else if(ch.top() == '('){
                    ch.pop();
                }
            }

            else if(str[i] == ']'){
                if(ch.empty() || ch.top() != '['){
                    result = false;
                    break;
                }
                else if(ch.top() == '['){
                    ch.pop();
                }
            }
            

        }
        if(result && ch.empty()){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }

        
    }
    
    return 0;
}