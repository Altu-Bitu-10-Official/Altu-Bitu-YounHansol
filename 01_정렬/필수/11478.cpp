#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    set<string> str;

    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < s.length(); j++){
            str.insert(s.substr(i,j));
        }
    }

    cout << str.size();
}