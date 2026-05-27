#include <iostream>
#include <vector>

using namespace std;

int op[4];
int MAX = -1000000000;
int MIN = 1000000000;

void backtracking(int idx, int n, vector<int> &arr, int current){
    if(idx == n){
        //최대값, 최솟값 갱신
       if(current > MAX){
        MAX = current;
       }
       if(current < MIN){
        MIN = current;
       }
        return;
    }

    for(int i = 0; i < 4; i++){
        if(op[i] > 0){
            op[i]--;

            if(i==0){
                backtracking(idx+1, n, arr, current+arr[idx]);
            }
            else if(i==1){
                backtracking(idx+1, n, arr, current-arr[idx]);
            }
            else if(i==2){
                backtracking(idx+1, n, arr, current*arr[idx]);
            }
            else if(i==3){
                backtracking(idx+1, n, arr, current/arr[idx]);
            }

            op[i]++;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    backtracking(1, n, arr, arr[0]);

    cout << MAX << '\n';
    cout << MIN << '\n';

    return 0;
}