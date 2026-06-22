#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int left, int right, int target, vector<int> &arr){
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){
            return 1;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return 0;
}

int main(){
    int n, m, input;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    while(m--){
        cin >> input;
        cout << binarySearch(0, n-1, input, arr) << ' ';
    }
}