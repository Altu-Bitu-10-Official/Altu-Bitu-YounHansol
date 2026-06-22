#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(int left, int right, int m, vector<int> &arr){
    int maxLen = 0; // 최대길이 저장

    while(left <= right){
        int mid = (left+right)/2;

        int cnt = 0;
        
        for(int i = 0; i < arr.size(); i++){
            cnt += arr[i]/mid;
        }

        if(cnt >= m){
            maxLen = mid;
            left = mid+1;
        }
        else{
            right = mid -1;
        }
    }
    return maxLen;
}

int main(){
    int m, n, input;

    cin >> m >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << search(1, arr[n-1], m, arr) << '\n';
}