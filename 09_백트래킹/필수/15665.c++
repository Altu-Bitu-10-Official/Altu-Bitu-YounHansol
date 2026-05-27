#include <iostream>
#include <vector>
#include <set>

using namespace std;

void backtracking(int idx, int m, vector<int> &arr, vector<int> &sequence)
{
    if(idx == m){
        for(auto x:sequence){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        sequence[idx] = arr[i];
        backtracking(idx + 1, m, arr, sequence);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    set<int> result;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        result.insert(x);
    }

    vector<int> arr(result.begin(), result.end());

    vector<int> sequence(m);

    backtracking(0, m, arr, sequence);
}