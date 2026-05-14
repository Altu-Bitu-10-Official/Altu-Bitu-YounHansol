#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLISLength(int n, vector<int> &a){
    vector<int> ans(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                ans[i] = max(ans[i], ans[j]+1);
            }
        }
    }
    int max_len = 0;
    for(int i = 0; i < n; i++){
        max_len = max(max_len, ans[i]);
    }

    return max_len;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    cout << getLISLength(n, a);

    return 0;
}