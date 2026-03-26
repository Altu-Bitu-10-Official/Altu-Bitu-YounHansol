#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<char> ch;

    string str;

    while(true){
        getline(cin, str);
        if(str == "."){
            cout << "yes" << '\n';
            break;
        }

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '['){
                ch.push(str[i]);
            }
            else if(str[i] == ')'){
                if(ch.empty() || ch.size)
            }
            

        }
        if(ch.empty()){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }

        
    }
    
    return 0;
}